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


#ifndef SPATEM_HPP_XGC8NRDI
#define SPATEM_HPP_XGC8NRDI

#include "vanetza-extension/asn1/asn1c_wrapper.hpp"
#include "vanetza-extension/asn1/its/SPATEM.h"

namespace vanetzaExtension
{
namespace asn1
{

class Spatem : public asn1c_per_wrapper<SPATEM_t>
{
public:
    using wrapper = asn1c_per_wrapper<SPATEM_t>;
    Spatem() : wrapper(asn_DEF_SPATEM) {}
};

} // namespace asn1
} // namespace vanetzaExtension

#endif /* SPATEM_HPP_XGC8NRDI */

