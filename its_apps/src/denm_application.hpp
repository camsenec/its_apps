/* 
 * (C) 2022 Tomoya Tanaka <deepsky2221@gmail.com> 
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


#ifndef DENM_APPLICATION_HPP_EUIC2VFR
#define DENM_APPLICATION_HPP_EUIC2VFR

#include "application.hpp"
#include "vanetza-extension/asn1/denm.hpp"
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>

class DenmApplication : public Application
{
public:
    DenmApplication() = default;
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void print_received_message(bool flag);

private:
    bool print_rx_msg_ = false;

protected:
    vanetzaExtension::asn1::Denm createMessageSkeleton(const vanetza::PositionFix& position);
};

#endif /* DENM_APPLICATION_HPP_EUIC2VFR */