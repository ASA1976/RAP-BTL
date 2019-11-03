// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef REPRESENTATION_MODULE
#define REPRESENTATION_MODULE
#include "location.hpp"

/**
 * @brief   
 *     Data to byte array representation facilitation.
 * @details 
 *     Data to byte array representation facilitation.
 */
namespace representation {

using ::location::Referential;

/**
 * @brief
 *     Data type to character array representation.
 * @details
 *     This type alias is used to represent a data type as a constant 
 *     character array of equal byte length.
 * @tparam Subjective
 *     The data type of the subject being represented as a character array.
 */
template <typename Subjective>
using NativelyConstant = const unsigned char[sizeof(Subjective)];

/**
 * @brief
 *     Data type to character array representation.
 * @details
 *     This type alias is used to represent a data type as a modifiable 
 *     character array of equal byte length.
 * @tparam Subjective
 *     The data type of the subject being represented as a character array.
 */
template <typename Subjective>
using NativelyModifiable = unsigned char[sizeof(Subjective)];

/**
 * @brief 
 *     Addresses a data subject as a character array.
 * @details
 *     Refers to the memory space of the subject data instance as a 
 *     constant character array reference.
 * @tparam Subjective
 *     The data type of the subject being represented as a character array.
 * @param[in] subject
 *     Reference to a constant subject instance.
 * @return
 *     Reference to the character array representation of the memory space.
 */
template <typename Subjective>
static inline Referential<NativelyConstant<Subjective>>
AddressNatively(
    Referential<const Subjective>
        subject)
{
    using namespace ::location;
    using Specific = Locational<NativelyConstant<Subjective>>;
    Specific bytes = (Specific)Locate(subject).at;
    return Refer(bytes).to;
}

/**
 * @brief 
 *     Addresses a data subject as a character array.
 * @details
 *     Refers to the memory space of the subject data instance as a 
 *     modifiable character array reference.
 * @tparam Subjective
 *     The data type of the subject being represented as a character array.
 * @param[in] subject
 *     Reference to a modifiable subject instance.
 * @return
 *     Reference to the character array representation of the memory space.
 */
template <typename Subjective>
static inline Referential<NativelyModifiable<Subjective>>
AddressNatively(
    Referential<Subjective>
        subject)
{
    using namespace ::location;
    using Specific = Locational<NativelyModifiable<Subjective>>;
    Specific bytes = (Specific)Locate(subject).at;
    return Refer(bytes).to;
}

}

#endif
