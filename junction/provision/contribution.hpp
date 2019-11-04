// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_CONTRIBUTION_MODULE
#define JUNCTION_PROVISION_CONTRIBUTION_MODULE
#include "../../attribution.hpp"
#include "../consecution.hpp"
#include "../provision.hpp"

namespace junction {

namespace provision {

/**
 * @brief         
 *     Linked list pool resource management implementation.
 * @details       
 *     Linked list pool resource management implementation.
 */
namespace contribution {

using ::attribution::Tributary;
using consecution::Concede;
using consecution::Concessive;

template <
    typename Natural,
    typename Elemental,
    const bool Safety>
static inline bool
Distribute(
    Referential<SinglyJunctive<Natural, Elemental>>
        list,
    Referential<SinglyPositional<Elemental>>
        position)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    Locational<SinglyNodal<Elemental>> node;
    node = Reclaim(list);
    if (Safety && !node)
        return false;
    UnsetNext(node);
    if (list.last)
        SetNext(list.last, node);
    else
        list.first = node;
    list.last = node;
    list.count++;
    position.at = node;
    return true;
}

template <
    typename Natural,
    typename Elemental,
    const bool Safety>
static inline bool
Distribute(
    Referential<DoublyJunctive<Natural, Elemental>>
        list,
    Referential<DoublyPositional<Elemental>>
        position)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    Locational<DoublyNodal<Elemental>> node;
    node = Reclaim(list);
    if (Safety && !node)
        return false;
    UnsetNext(node);
    SetPrevious(node, list.last);
    if (list.last)
        SetNext(list.last, node);
    else
        list.first = node;
    list.last = node;
    list.count++;
    position.at = node;
    return true;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Concessive<Connective, Natural, Elemental>> Concede>
static inline bool
Retribute(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Concede(list, position, 1);
}

template <
    typename Natural,
    typename Elemental>
constexpr Tributary<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural>
    SingleContributor = {
        Survey<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Distribute<Natural, Elemental, false>,
        Retribute<SinglyLinked<Elemental>, Natural, Elemental, Concede<Natural, Elemental>>,
        RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Tributary<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural>
    DoubleContributor = {
        Survey<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Distribute<Natural, Elemental, false>,
        Retribute<DoublyLinked<Elemental>, Natural, Elemental, Concede<Natural, Elemental>>,
        RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>
    };

}

}

}

#endif
