# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                                                                               #
# Copyright (c) 2015 The Regents of the University of California, Author: William Lenthe        #
#                                                                                               #
# This program is free software: you can redistribute it and/or modify it under the terms of    #
# the GNU Lesser General Public License as published by the Free Software Foundation, either    #
# version 2 of the License, or (at your option) any later version.                              #
#                                                                                               #
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;     #
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     #
# See the GNU Lesser General Public License for more details.                                   #
#                                                                                               #
# You should have received a copy of the GNU Lesser General Public License                      #
# along with this program.  If not, see <http://www.gnu.org/licenses/>.                         #
#                                                                                               #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

set (${PLUGIN_NAME}_FilterParameters_SRCS
  ${${PLUGIN_NAME}_SOURCE_DIR}/FilterParameters/Symmetric6x6FilterParameter.cpp
  ${${PLUGIN_NAME}_SOURCE_DIR}/FilterParameters/FloatVec4FilterParameter.cpp

)

set (${PLUGIN_NAME}_FilterParameters_HDRS
    ${${PLUGIN_NAME}_SOURCE_DIR}/FilterParameters/Symmetric6x6FilterParameter.h
    ${${PLUGIN_NAME}_SOURCE_DIR}/FilterParameters/FloatVec4FilterParameter.h
)
cmp_IDE_SOURCE_PROPERTIES( "FilterParameters" "${${PLUGIN_NAME}_FilterParameters_HDRS}" "${${PLUGIN_NAME}_FilterParameters_SRCS}" "${PROJECT_INSTALL_HEADERS}")
