// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COMPARISON_MODULE
#define COMPARISON_MODULE
#include "location.hpp"

namespace comparison {

    using ::location::Referential;

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    using BinaryComparative = bool(
        Referential< const Subjective >,
        Referential< const Relative >
    );

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    struct Equative {

        Referential< BinaryComparative< Subjective, Relative > >
            is_equal,
            is_not_equal;

    };

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    struct Relational {

        Referential< BinaryComparative< Subjective, Relative > >
            is_lesser,
            is_greater,
            is_not_greater,
            is_not_lesser;

    };

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    struct Comparative {

        Referential< const Equative< Subjective, Relative > >
            equality;

        Referential< const Relational< Subjective, Relative > >
            relation;

    };

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsEqual(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject == relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsNotEqual(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject != relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsLesser(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject < relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsGreater(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject > relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsNotGreater(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject <= relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    static inline bool
    IsNotLesser(
        Referential< const Subjective >
            subject,
        Referential< const Relative >
            relative
    ) {
        return subject >= relative;
    }

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    constexpr Equative< Subjective, Relative >
    Equality = {
        IsEqual< Subjective, Relative >,
        IsNotEqual< Subjective, Relative >
    };

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    constexpr Relational< Subjective, Relative >
    Relation = {
        IsLesser< Subjective, Relative >,
        IsGreater< Subjective, Relative >,
        IsNotGreater< Subjective, Relative >,
        IsNotLesser< Subjective, Relative >
    };

    template <
        typename Subjective,
        typename Relative = Subjective
    >
    constexpr Comparative< Subjective, Relative >
    Comparison = {
        Equality< Subjective, Relative >,
        Relation< Subjective, Relative >
    };

}

#endif
