// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_MODULE
#define JUNCTION_MODULE
#include "allocation.hpp"
#include "trajection.hpp"

namespace junction {

    using namespace ::allocation;
    using namespace ::trajection;
    using ::comparison::Equative;
    using ::comparison::Relational;
    using ::comparison::Comparative;

    template <
        typename Elemental
    >
    struct Junctional {

        Locational< Junctional< Elemental > >
            previous,
            next;

        Elemental
            element;

    };

    template <
        typename Natural,
        typename Elemental
    >
    struct Junctive {

        Natural
            count,
            total;

        Locational< Junctional< Elemental > >
            first,
            last,
            unused;

    };

    template <
        typename Natural,
        typename Elemental
    >
    struct Adjunctive {

        Referential< Locational< Junctional< Elemental > >(
            Referential< Junctive< Natural, Elemental > >
        ) >
            allocate;

        Referential< bool(
            Referential< Junctive< Natural, Elemental > >,
            Referential< Locational< Junctional< Elemental > > >
        ) >
            deallocate;

        Referential< Locational< Junctional< Elemental > >(
            Referential< Junctive< Natural, Elemental > >,
            Referential< const Elemental >
        ) >
            proclaim;

    };

    template <
        typename Elemental
    >
    using Positional = Positive< Junctional< Elemental > >;

    template <
        typename Elemental
    >
    static inline bool
    IsEqual(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        return base.at == relative.at;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsNotEqual(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        return base.at != relative.at;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsGreater(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        Locational< Junctional< Elemental > >
            current;
        if (base.at == relative.at)
            return false;
        for (current = base.at->previous; current; current = current->previous)
            if (current == relative.at)
                return true;
        return false;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsGreaterChecksForNull(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        if (!base.at)
            throw base.at;
        if (!relative.at)
            throw relative.at;
        return IsGreater( base, relative );
    }

    template <
        typename Elemental
    >
    static inline bool
    IsLesser(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        Locational< Junctional< Elemental > >
            current;
        if (base.at == relative.at)
            return false;
        for (current = base.at->next; current; current = current->next)
            if (current == relative.at)
                return true;
        return false;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsLesserChecksForNull(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        if (!base.at)
            throw base.at;
        if (!relative.at)
            throw relative.at;
        return IsLesser( base, relative );
    }

    template <
        typename Elemental
    >
    static inline bool
    IsNotLesser(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        Locational< Junctional< Elemental > >
            current;
        if (base.at == relative.at)
            return true;
        for (current = base.at->previous; current; current = current->previous)
            if (current == relative.at)
                return true;
        return false;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsNotLesserChecksForNull(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        if (!base.at)
            throw base.at;
        if (!relative.at)
            throw relative.at;
        return IsNotLesser( base, relative );
    }

    template <
        typename Elemental
    >
    static inline bool
    IsNotGreater(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        Locational< Junctional< Elemental > >
            current;
        if (base.at == relative.at)
            return true;
        for (current = base.at->next; current; current = current->next)
            if (current == relative.at)
                return true;
        return false;
    }

    template <
        typename Elemental
    >
    static inline bool
    IsNotGreaterChecksForNull(
        Referential< const Positional< Elemental > >
            base,
        Referential< const Positional< Elemental > >
            relative
    ) {
        if (!base.at)
            throw base.at;
        if (!relative.at)
            throw relative.at;
        return IsNotGreater( base, relative );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< Junctive< Natural, Elemental > >
    Initialize(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        list.count = list.total = 0;
        list.first = list.last = list.unused = 0;
        return list;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    Empty(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        bool
            actioned = false;
        if (list.last) {
            list.last->next = list.unused;
            if (list.unused)
                list.unused->previous = list.last;
            list.unused = list.first;
            actioned = true;
        }
        list.first = list.last = 0;
        list.count = 0;
        return actioned;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Locational< Junctional < Elemental > >
    Reclaim(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            result;
        result = list.unused;
        if (result) {
            list.unused = result->next;
            if (list.unused)
                list.unused->previous = 0;
            result->next = 0;
        }
        return result;
    }

    template <
        typename Natural,
        typename Elemental,
        Referential< const Adjunctive< Natural, Elemental > >
            Adjunct
    >
    static inline bool
    Free(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            next;
        if (!list.unused)
            return false;
        next = list.unused->next;
        if (!Adjunct.deallocate( list, list.unused ))
            return false;
        list.unused = next;
        if (next)
            next->previous = 0;
        return list.unused;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Locational< Junctional< Elemental > >
    AllocateNothing(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return 0;
    }

    template <
        typename Disclaimable,
        typename Natural,
        typename Elemental,
        Referential< const Allocative< DefaultClaimable< Junctional< Elemental > >, Disclaimable > >
            Allocator
    >
    static inline Locational< Junctional< Elemental > >
    AllocateDefault(
        Referential< Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            result;
        Allocator.claim( result );
        if (result)
            list.total++;
        return result;
    }

    template <
        typename Claimable,
        typename Natural,
        typename Elemental,
        Referential< const Allocative< Claimable, DefaultDisclaimable< Junctional< Elemental > > > >
            Allocator
    >
    static inline bool
    DeallocateDefault(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Locational< Junctional< Elemental > > >
            node
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (node) {
            Allocator.disclaim( node );
            list.total--;
            return true;
        }
        return false;
    }

    template <
        typename Disclaimable,
        typename Natural,
        typename Elemental,
        Referential< const Allocative< DefaultClaimable< Junctional< Elemental > >, Disclaimable > >
            Allocator
    >
    static inline Locational< Junctional< Elemental > >
    ProclaimDefault(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< const Elemental >
            value
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            result;
        result = Reclaim( list );
        if (!result) {
            Allocator.claim( result );
            if (!result)
                return 0;
            list.total++;
        }
        result->element = value;
        return result;
    }

    template <
        typename Disclaimable,
        typename Natural,
        typename Elemental,
        Referential< const Allocative< CopyClaimable< Junctional< Elemental > >, Disclaimable > >
            Allocator
    >
    static inline Locational< Junctional< Elemental > >
    ProclaimCopy(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< const Elemental >
            value
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        const Junctional< Elemental >
            copy = {0, 0, value};
        Locational< Junctional < Elemental > >
            result;
        Allocator.claim( result, copy );
        if (result)
            list.total++;
        return result;
    }

    template <
        typename Natural,
        typename Elemental,
        Referential< const Adjunctive< Natural, Elemental > >
            Adjunct
    >
    static inline bool
    Instantiate(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< const Natural >
            count
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            current;
        while (list.total - list.count < count) {
            current = Adjunct.allocate( list );
            if (!current)
                return false;
            current->next = list.unused;
            if (list.unused)
                list.unused->previous = current;
            list.unused = current;
        }
        return true;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    Contains(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        Locational< Junctional< Elemental > >
            current;
        for (current = list.first; current; current = current->next)
            if (current == position.at)
                return true;
        return false;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    ContainsChecksForNull(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        return Contains( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Conferential< const Elemental >
    GoRead(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            DoDefer = Defer< Elemental >;
        return DoDefer( position.at->element );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Conferential< const Elemental >
    GoReadSafely(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!ContainsChecksForNull( list, position ))
            throw position;
        return GoRead( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Conferential< Elemental >
    GoWrite(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            DoConfer = Confer< Elemental >;
        return DoConfer( position.at->element );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Conferential< Elemental >
    GoWriteSafely(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!ContainsChecksForNull( list, position ))
            throw position;
        return GoWrite( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginReadIncrement(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = list.first;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginReadIncrementSafely(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!list.first)
            throw list;
        return BeginReadIncrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginWriteIncrement(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = list.first;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginWriteIncrementSafely(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!list.first)
            throw list;
        return BeginWriteIncrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    IncrementBegins(
        Referential< const Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return list.first;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseReadIncrement(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = position.at->next;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseReadIncrementSafely(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        if (!position.at->next)
            throw position;
        return TraverseReadIncrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseWriteIncrement(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = position.at->next;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseWriteIncrementSafely(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        if (!position.at->next)
            throw position;
        return TraverseWriteIncrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    IncrementTraversable(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return position.at->next;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    IncrementTraversableChecksForNull(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        return IncrementTraversable( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginReadDecrement(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = list.last;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginReadDecrementSafely(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!list.last)
            throw list;
        return BeginReadDecrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginWriteDecrement(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = list.last;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    BeginWriteDecrementSafely(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!list.last)
            throw list;
        return BeginWriteDecrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    DecrementBegins(
        Referential< const Junctive< Natural, Elemental > >
            list
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return list.last;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseReadDecrement(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = position.at->previous;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseReadDecrementSafely(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        if (!position.at->previous)
            throw position;
        return TraverseReadDecrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseWriteDecrement(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position.at = position.at->previous;
        return position;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Positional< Elemental > >
    TraverseWriteDecrementSafely(
        Referential< Junctive< Natural, Elemental > >
            list,
        Referential< Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        if (!position.at->previous)
            throw position;
        return TraverseWriteDecrement( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    DecrementTraversable(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return position.at->previous;
    }

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    DecrementTraversableChecksForNull(
        Referential< const Junctive< Natural, Elemental > >
            list,
        Referential< const Positional< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!position.at)
            throw position;
        return DecrementTraversable( list, position );
    }

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Adjunctive< Natural, Elemental >
    DefaultNewAdjunct = {
        AllocateDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultNew< Junctional< Elemental > > >,
        DeallocateDefault< DefaultClaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultNew< Junctional< Elemental > > >,
        ProclaimDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultNew< Junctional< Elemental > > >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Adjunctive< Natural, Elemental >
    CopyNewAdjunct = {
        AllocateNothing< Natural, Elemental >,
        DeallocateDefault< CopyClaimable< Junctional< Elemental > >, Natural, Elemental, FastCopyNew< Junctional< Elemental > > >,
        ProclaimCopy< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastCopyNew< Junctional< Elemental > > >
    };

    template <
        typename Elemental
    >
    constexpr Equative< Positional< Elemental > >
    Equality = {
        IsEqual< Elemental >,
        IsNotEqual< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Relational< Positional< Elemental > >
    Relation = {
        IsLesser< Elemental >,
        IsGreater< Elemental >,
        IsNotGreater< Elemental >,
        IsNotLesser< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Relational< Positional< Elemental > >
    RelationChecksForNull = {
        IsLesserChecksForNull< Elemental >,
        IsGreaterChecksForNull< Elemental >,
        IsNotGreaterChecksForNull< Elemental >,
        IsNotLesserChecksForNull< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Comparative< Positional< Elemental >  >
    Comparison = {
        Equality< Elemental >,
        Relation< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Comparative< Positional< Elemental >  >
    ComparisonChecksForNull = {
        Equality< Elemental >,
        RelationChecksForNull< Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Vectorial< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadVector = {
        Comparison< Elemental >,
        Contains< Natural, Elemental >,
        GoRead< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Vectorial< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadVector = {
        ComparisonChecksForNull< Elemental >,
        ContainsChecksForNull< Natural, Elemental >,
        GoReadSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Vectorial< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteVector = {
        Comparison< Elemental >,
        Contains< Natural, Elemental >,
        GoWrite< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Vectorial< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteVector = {
        ComparisonChecksForNull< Elemental >,
        ContainsChecksForNull< Natural, Elemental >,
        GoWriteSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadIncrementScale = {
        Comparison< Elemental >,
        BeginReadIncrement< Natural, Elemental >,
        TraverseReadIncrement< Natural, Elemental >,
        GoRead< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadIncrementScale = {
        ComparisonChecksForNull< Elemental >,
        BeginReadIncrementSafely< Natural, Elemental >,
        TraverseReadIncrementSafely< Natural, Elemental >,
        GoReadSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteIncrementScale = {
        Comparison< Elemental >,
        BeginWriteIncrement< Natural, Elemental >,
        TraverseWriteIncrement< Natural, Elemental >,
        GoWrite< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteIncrementScale = {
        ComparisonChecksForNull< Elemental >,
        BeginWriteIncrementSafely< Natural, Elemental >,
        TraverseWriteIncrementSafely< Natural, Elemental >,
        GoWriteSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadDecrementScale = {
        Comparison< Elemental >,
        BeginReadDecrement< Natural, Elemental >,
        TraverseReadDecrement< Natural, Elemental >,
        GoRead< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadDecrementScale = {
        ComparisonChecksForNull< Elemental >,
        BeginReadDecrementSafely< Natural, Elemental >,
        TraverseReadDecrementSafely< Natural, Elemental >,
        GoReadSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteDecrementScale = {
        Comparison< Elemental >,
        BeginWriteDecrement< Natural, Elemental >,
        TraverseWriteDecrement< Natural, Elemental >,
        GoWrite< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteDecrementScale = {
        ComparisonChecksForNull< Elemental >,
        BeginWriteDecrementSafely< Natural, Elemental >,
        TraverseWriteDecrementSafely< Natural, Elemental >,
        GoWriteSafely< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Natural, Elemental >,
        ReadDecrementScale< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadLiner = {
        SafeReadIncrementScale< Natural, Elemental >,
        SafeReadDecrementScale< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteLiner = {
        WriteIncrementScale< Natural, Elemental >,
        WriteDecrementScale< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteLiner = {
        SafeWriteIncrementScale< Natural, Elemental >,
        SafeWriteDecrementScale< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Elemental >,
        IncrementBegins< Natural, Elemental >,
        IncrementTraversable< Natural, Elemental >,
        Contains< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Elemental >,
        IncrementBegins< Natural, Elemental >,
        IncrementTraversableChecksForNull< Natural, Elemental >,
        ContainsChecksForNull< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Elemental >,
        IncrementBegins< Natural, Elemental >,
        IncrementTraversable< Natural, Elemental >,
        Contains< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Elemental >,
        IncrementBegins< Natural, Elemental >,
        IncrementTraversableChecksForNull< Natural, Elemental >,
        ContainsChecksForNull< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Elemental >,
        DecrementBegins< Natural, Elemental >,
        DecrementTraversable< Natural, Elemental >,
        Contains< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Elemental >,
        DecrementBegins< Natural, Elemental >,
        DecrementTraversableChecksForNull< Natural, Elemental >,
        ContainsChecksForNull< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Elemental >,
        DecrementBegins< Natural, Elemental >,
        DecrementTraversable< Natural, Elemental >,
        ContainsChecksForNull< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Directional< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Elemental >,
        DecrementBegins< Natural, Elemental >,
        DecrementTraversableChecksForNull< Natural, Elemental >,
        ContainsChecksForNull< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Axial< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    ReadAxis = {
        ReadIncrementDirection< Natural, Elemental >,
        ReadDecrementDirection< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Axial< const Junctive< Natural, Elemental >, Positional< Elemental >, const Elemental >
    SafeReadAxis = {
        SafeReadIncrementDirection< Natural, Elemental >,
        SafeReadDecrementDirection< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Axial< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    WriteAxis = {
        WriteIncrementDirection< Natural, Elemental >,
        WriteDecrementDirection< Natural, Elemental >
    };

    template <
        typename Natural,
        typename Elemental
    >
    constexpr Axial< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Elemental >,
        SafeWriteDecrementDirection< Natural, Elemental >
    };

}

#endif
