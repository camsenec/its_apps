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


#ifndef DENM_FUNCTIONS_HPP_PUFKBEM8
#define DENM_FUNCTIONS_HPP_PUFKBEM8


namespace vanetzaExtension
{

// forward declaration of DENM message wrapper
namespace asn1 { class Denm; }

namespace facilities
{
namespace denm
{

/**
 * Print DENM content with indentation of nested fields
 * \param os output stream
 * \param denm DEN message
 * \param indent indentation marker, by default one tab per level
 * \param start initial level of indentation
 */
void print_indented(std::ostream& os, const asn1::Denm& den, const std::string& indent = "\t", unsigned start = 0);

} // namespace denm
} // namespace facilities
} // namespace vanetzaExtension

#endif /* DENM_FUNCTIONS_HPP_PUFKBEM8 */
