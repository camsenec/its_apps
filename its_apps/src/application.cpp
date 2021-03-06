/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/socktap/application.cpp>
 * at 2022-05-06.
 * 
 * This file is part of its_apps.
 *
 * its_apps is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or 
 * any later version.
 * its_apps is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License and 
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * and GNU Lesser General Public License along with its_apps. 
 * If not, see <https://www.gnu.org/licenses/>. 
 */


#include "application.hpp"
#include <vanetza/btp/header.hpp>
#include <vanetza/btp/header_conversion.hpp>
#include <cassert>

using namespace vanetza;

Application::DataConfirm Application::request(const DataRequest& request, DownPacketPtr packet)
{
    DataConfirm confirm(DataConfirm::ResultCode::Rejected_Unspecified);
    if (router_ && packet) {
        btp::HeaderB btp_header;
        btp_header.destination_port = this->port();
        btp_header.destination_port_info = host_cast<uint16_t>(0);
        packet->layer(OsiLayer::Transport) = btp_header;

        switch (request.transport_type) {
            case geonet::TransportType::SHB:
                confirm = router_->request(request_shb(request), std::move(packet));
                break;
            case geonet::TransportType::GBC:
                confirm = router_->request(request_gbc(request), std::move(packet));
                break;
            default:
                // TODO remaining transport types are not implemented
                break;
        }
    }

    return confirm;
}

void initialize_request(const Application::DataRequest& generic, geonet::DataRequest& geonet)
{
    geonet.upper_protocol = geonet::UpperProtocol::BTP_B;
    geonet.communication_profile = generic.communication_profile;
    geonet.its_aid = generic.its_aid;
    if (generic.maximum_lifetime) {
        geonet.maximum_lifetime = generic.maximum_lifetime.get();
    }
    geonet.repetition = generic.repetition;
    if (generic.maximum_hop_limit) {
        geonet.max_hop_limit = generic.maximum_hop_limit.get();
    }
    geonet.traffic_class = generic.traffic_class;
}

geonet::GbcDataRequest Application::request_gbc(const DataRequest& generic)
{
    assert(router_);
    geonet::GbcDataRequest gbc(router_->get_mib());
    initialize_request(generic, gbc);
    gbc.destination = boost::get<geonet::Area>(generic.destination);
    return gbc;
}

geonet::ShbDataRequest Application::request_shb(const DataRequest& generic)
{
    assert(router_);
    geonet::ShbDataRequest shb(router_->get_mib());
    initialize_request(generic, shb);
    return shb;
}

Application::PromiscuousHook* Application::promiscuous_hook()
{
    return nullptr;
}
