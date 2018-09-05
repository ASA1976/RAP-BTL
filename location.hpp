// � 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCATION_MODULE
#define LOCATION_MODULE

namespace location {

    template <
        typename Subjective
    >
    using Locational = Subjective*;

    template <
        typename Subjective
    >
    using Referential = Subjective&;

    template <
        typename Subjective
    >
    using Deferential = Subjective&&;

    template <
        typename Subjective
    >
    struct Positive {

        Locational< Subjective >
            at;

    };

    template <
        typename Subjective
    >
    struct Conferential {

        Referential< Subjective >
            to;

    };

    template <
        typename Subjective
    >
    struct Deferent {

        Deferential< Subjective >
            to;

    };

    template <
        typename Subjective
    >
    static inline Positive< Subjective >
    Locate(
        Referential< Subjective >
            subject
    ) {
        const Positive< Subjective >
            posit = {&subject};
        return posit;
    }

    template <
        typename Subjective
    >
    static inline Conferential< Subjective >
    Confer(
        Referential< Subjective >
            subject
    ) {
        const Conferential< Subjective >
            conferment = {subject};
        return conferment;
    }

    template <
        typename Subjective
    >
    static inline Deferent< Subjective >
    Defer(
        Referential< Subjective >
            subject
    ) {
        const Deferent< Subjective >
            deferment = {subject};
        return deferment;
    }

    template <
        typename Subjective
    >
    static inline Conferential< const Subjective >
    Deter(
        Referential< Subjective >
            subject
    ) {
		static auto&
			View = Confer< const Subjective >;
        return View( subject );
    }

    template <
        typename Subjective
    >
    static inline Conferential< Subjective >
    Refer(
        const Locational< Subjective >
            locality
    ) {
        return Confer( *locality );
    }

}

#endif
