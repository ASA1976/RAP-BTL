// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_MODULE
#define JUNCTION_PROVISION_MODULE
#include "../junction.hpp"

namespace junction {

/**
     * @brief         
     *     Linked list resource management common functionality.
     * @details       
     *     Association
     *     -----------
     *     Linked list resource management common functionality.
     */
namespace provision {

    using ::allocation::DefaultAllocative;

    template <
        typename Connective,
        typename Natural,
        typename Elemental>
    static inline Natural
    Survey(
        Referential<const Junctive<Connective, Natural, Elemental>>
            list)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return list.total;
    }

    template <
        typename Natural,
        typename Elemental,
        const bool
            Safety>
    static inline bool
    Protract(
        Referential<SinglyJunctive<Natural, Elemental>>
            list,
        Referential<SinglyPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Locational<SinglyNodal<Elemental>>
            first, node;
        Natural
            index;
        first = Reclaim(list);
        if (Safety && !first)
            return false;
        node = first;
        for (index = 1; index < count; index++) {
            node = GetNext(node);
            if (Safety && !node)
                return false;
        }
        UnsetNext(node);
        if (list.last)
            SetNext(list.last, first);
        else
            list.first = first;
        list.last = node;
        list.count += count;
        position.at = first;
        return true;
    }

    template <
        typename Natural,
        typename Elemental,
        const bool
            Safety>
    static inline bool
    Protract(
        Referential<DoublyJunctive<Natural, Elemental>>
            list,
        Referential<DoublyPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Locational<DoublyNodal<Elemental>>
            first, node;
        Natural
            index;
        first = Reclaim(list);
        if (Safety && !first)
            return false;
        node = first;
        for (index = 1; index < count; index++) {
            node = GetNext(node);
            if (Safety && !node)
                return false;
        }
        UnsetNext(node);
        SetPrevious(first, list.last);
        if (list.last)
            SetNext(list.last, first);
        else
            list.first = first;
        list.last = node;
        list.count += count;
        position.at = first;
        return true;
    }

}

}

#endif
