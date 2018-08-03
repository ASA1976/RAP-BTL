// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SORTATION_MODULE
#define SORTATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"

namespace sortation {

    using namespace ::trajection;
    using ::comparison::BinaryComparative;

    template <
        typename Evaluative
    >
    using Assortive = BinaryComparative< Evaluative, Evaluative >;

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchLinearly(
        Referential< const Spatial >
            space,
        Referential< const Scalar< const Spatial, Positional, Natural, const Evaluative > >
            scale,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Natural
            extent
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        while (true) {
            if (Equate( scale.go( space, position ).to, value )) 
                return true;
            else if (!extent--)
                return false;
            scale.traverse( space, position, 1 );
        }
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< const Scalar< const Spatial, Positional, Natural, const Evaluative > >
            Scale,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchLinearly(
        Referential< const Spatial >
            space,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Natural
            extent
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Search = SearchLinearly< Spatial, Positional, Natural, Evaluative, Equate >;
        return Search( space, Scale, value, position, extent );
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchRecurrenceLinearly(
        Referential< const Spatial >
            space,
        Referential< const Scalar< const Spatial, Positional, Natural, const Evaluative > >
            scale,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Referential< Natural >
            extent
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        while (true) {
            if (Equate( scale.go( space, position ).to, value )) 
                return true;
            else if (!extent--)
                return false;
            scale.traverse( space, position, 1 );
        }
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< const Scalar< const Spatial, Positional, Natural, const Evaluative > >
            Scale,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchRecurrenceLinearly(
        Referential< const Spatial >
            space,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Referential< Natural >
            extent
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Search = SearchRecurrenceLinearly< Spatial, Positional, Natural, Evaluative, Equate >;
        return Search( space, Scale, value, position, extent );
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Lineal< const Spatial, Positional, Natural, const Evaluative > >
            liner,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Natural
            before,
        Natural 
            after
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        auto&
            go = liner.increment.go;
        Natural
            moves,
            remainder,
            difference;
        while (true) {
            if (Equate( go( space, position ).to, value ))
                return true;
            if (Order( go( space, position ).to, value )) {
                if (!after)
                    return false;
                remainder = after % 2;
                moves = after / 2 + remainder;
                difference = after - moves;
                before = difference - (remainder ? 0 : 1);
                after = difference;
                liner.increment.traverse( space, position, moves );
            } else {
                if (!before)
                    return false;
                remainder = before % 2;
                moves = before / 2 + remainder;
                difference = before - moves;
                after = difference - (remainder ? 0 : 1);
                before = difference;
                liner.decrement.traverse( space, position, moves );
            }
        }
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< const Lineal< const Spatial, Positional, Natural, const Evaluative > >
            Liner,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Natural
            before,
        Natural
            after
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Search = SearchBisectionally< Spatial, Positional, Natural, Evaluative, Equate, Order >;
        return Search( space, Liner, value, position, before, after );
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchRecurrenceBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Lineal< const Spatial, Positional, Natural, const Evaluative > >
            liner,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Referential< Natural >
            before,
        Referential< Natural >
            after
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        auto&
            go = liner.increment.go;
        Natural
            moves,
            remainder,
            difference,
            min,
            max;
        min = before;
        max = after;
        while (true) {
            if (Equate( go( space, position ).to, value ))
                return true;
            if (Order( go( space, position ).to, value )) {
                if (!max)
                    return false;
                remainder = max % 2;
                moves = max / 2 + remainder;
                before += moves;
                after -= moves;
                difference = max - moves;
                min = difference - (remainder ? 0 : 1);
                max = difference;
                liner.increment.traverse( space, position, moves );
            } else {
                if (!min)
                    return false;
                remainder = min % 2;
                moves = min / 2 + remainder;
                before -= moves;
                after += moves;
                difference = min - moves;
                max = difference - (remainder ? 0 : 1);
                min = difference;
                liner.decrement.traverse( space, position, moves );
            }
        }
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< const Lineal< const Spatial, Positional, Natural, const Evaluative > >
            Liner,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchRecurrenceBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position,
        Referential< Natural >
            before,
        Referential< Natural >
            after
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Search = SearchRecurrenceBisectionally< Spatial, Positional, Natural, Evaluative, Equate, Order >;
        return Search( space, Liner, value, position, before, after );
    }

}

#endif
