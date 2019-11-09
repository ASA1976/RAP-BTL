// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_MODULE
#define JUNCTION_MODULE
#include <allocation.hpp>
#include <trajection.hpp>

/**
 * @brief         
 *     Linked list management and trajection implementation.
 * @details       
 *     Linked list management and trajection implementation.
 */
namespace junction {

using ::allocation::Allocative;
using ::allocation::CopyClaimable;
using ::allocation::DefaultClaimable;
using ::allocation::DefaultDisclaimable;
using ::allocation::FastCopyNew;
using ::allocation::FastDefaultNew;
using ::comparison::Comparative;
using ::comparison::Equative;
using ::comparison::Relational;
using ::location::Conferential;
using ::location::Locational;
using ::location::Positive;
using ::location::Referential;
using ::trajection::Axial;
using ::trajection::Directional;
using ::trajection::Lineal;
using ::trajection::Scalar;
using ::trajection::Vectorial;

/**
 * @brief 
 *     Linked list node conformity.
 * @details  
 *     This type is used to represent a linked list node.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Elemental>
struct Nodal {

    Connective
        link; /**< Node link(s) substructure. */

    Elemental
        element; /**< Instance of the element at this node. */
};

/**
 * @brief 
 *     Single link conformity.
 * @details  
 *     This type is used to represent a singly connective list node link.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
struct SinglyLinked {

    Locational<Nodal<SinglyLinked<Elemental>, Elemental>>
        node; /**< Single node link. */
};

/**
 * @brief 
 *     Double link conformity.
 * @details  
 *     This type is used to represent a doubly connective list node link.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
struct DoublyLinked {

    Locational<Nodal<DoublyLinked<Elemental>, Elemental>>
        previous, /**< Link to previous node. */
        next; /**< Link to next node. */
};

/**
 * @brief 
 *     Singly linked node conformity.
 * @details  
 *     This type alias is used to represent a singly linked list node.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using SinglyNodal = Nodal<SinglyLinked<Elemental>, Elemental>;

/**
 * @brief 
 *     Doubly linked node conformity.
 * @details  
 *     This type alias is used to represent a doubly linked list node.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using DoublyNodal = Nodal<DoublyLinked<Elemental>, Elemental>;

/**
 * @brief 
 *     Linked list conformity.
 * @details  
 *     This type is used to represent a linked list.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Natural,
    typename Elemental>
struct Junctive {

    Locational<Nodal<Connective, Elemental>>
        first, /**< First node in the list. */
        last, /**< Last node in the list. */
        unused; /**< First unused node in a sublist of unused nodes. */

    Natural
        count, /**< Number of nodes in the active list. */
        total; /**< Total number of nodes in the active and unused sublists. */
};

/**
 * @brief 
 *     Singly linked list conformity.
 * @details  
 *     This type alias is used to represent a singly linked list.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Natural,
    typename Elemental>
using SinglyJunctive = Junctive<SinglyLinked<Elemental>, Natural, Elemental>;

/**
 * @brief 
 *     Doubly linked list conformity.
 * @details  
 *     This type alias is used to represent a doubly linked list.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Natural,
    typename Elemental>
using DoublyJunctive = Junctive<DoublyLinked<Elemental>, Natural, Elemental>;

/**
 * @brief
 *     Linked list node management classifier.
 * @details
 *     This type is used to manage linked list nodes, including enforcement
 *     of recycling policy.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Natural,
    typename Elemental>
struct Adjunctive {

    Referential<Locational<Nodal<Connective, Elemental>>(Referential<Junctive<Connective, Natural, Elemental>>)>
        allocate; /**< Allocates one or more uninitialized nodes.  
                   *   Implementations may simply return null if this 
                   *   operation is not supported.
                   */

    Referential<bool(Referential<Junctive<Connective, Natural, Elemental>>, Referential<Locational<Nodal<Connective, Elemental>>>)>
        deallocate; /**< Frees the memory used by one linked list node which
                     *   has already been removed from either the active 
                     *   node list or unused node sublist.
                     */

    Referential<Locational<Nodal<Connective, Elemental>>(Referential<Junctive<Connective, Natural, Elemental>>, Referential<const Elemental>)>
        proclaim; /**< Proclaims an element with the specified value.  
                   *   Implementations may recycle an unused node and assign
                   *   it the provided value or allocate and initialize a 
                   *   new node to the provided value.
                   */
};

/**
 * @brief 
 *     Singly linked list node management classifier.
 * @details  
 *     This type alias is used to represent a singly linked list node 
 *     management adjunct.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Natural,
    typename Elemental>
using SinglyAdjunctive = Adjunctive<SinglyLinked<Elemental>, Natural, Elemental>;

/**
 * @brief 
 *     Doubly linked list node management classifier.
 * @details  
 *     This type alias is used to represent a doubly linked list node 
 *     management adjunct.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Natural,
    typename Elemental>
using DoublyAdjunctive = Adjunctive<DoublyLinked<Elemental>, Natural, Elemental>;

/**
 * @brief
 *     Linked list position conformity.
 * @details
 *     This type alias is used to represent a position in the linked list.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Elemental>
using Positional = Positive<Nodal<Connective, Elemental>>;

/**
 * @brief 
 *     Singly linked list position conformity.
 * @details  
 *     This type alias is used to represent a position in singly linked 
 *     list.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using SinglyPositional = Positional<SinglyLinked<Elemental>, Elemental>;

/**
 * @brief 
 *     Doubly linked list position conformity.
 * @details  
 *     This type alias is used to represent a position in doubly linked 
 *     list.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using DoublyPositional = Positional<DoublyLinked<Elemental>, Elemental>;

/**
 * @brief 
 *     Function abstract used to get a polar position in the list.
 * @details  
 *     This function type alias is used to declare function references which
 *     return either the first or last node in the linked list.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Natural
 *     Type of unsigned integer.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Natural,
    typename Elemental>
using Original = Locational<Nodal<Connective, Elemental>>(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list);

/**
 * @brief 
 *     Function abstract used to get a node subsequent to another node.
 * @details  
 *     This function type alias is used to declare function references which
 *     return either the next or previous node in the linked list.
 * @tparam Connective
 *     Type of the node linkage.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Connective,
    typename Elemental>
using Subsequent = Locational<Nodal<Connective, Elemental>>(
    const Locational<Nodal<Connective, Elemental>>
        node);

template <
    typename Connective,
    typename Natural,
    typename Elemental>
constexpr Junctive<Connective, Natural, Elemental>
    InitializedList = { 0, 0, 0, 0, 0 };

template <typename Elemental>
static inline Locational<SinglyNodal<Elemental>>
GetNext(
    const Locational<SinglyNodal<Elemental>>
        node)
{
    return node->link.node;
}

template <typename Elemental>
static inline Locational<DoublyNodal<Elemental>>
GetNext(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    return node->link.next;
}

template <typename Elemental>
static inline Locational<DoublyNodal<Elemental>>
GetPrevious(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    return node->link.previous;
}

template <typename Elemental>
static inline void
SetNext(
    const Locational<SinglyNodal<Elemental>>
        node,
    const Locational<SinglyNodal<Elemental>>
        next)
{
    node->link.node = next;
}

template <typename Elemental>
static inline void
SetNext(
    const Locational<DoublyNodal<Elemental>>
        node,
    const Locational<DoublyNodal<Elemental>>
        next)
{
    node->link.next = next;
}

template <typename Elemental>
static inline void
SetPrevious(
    const Locational<DoublyNodal<Elemental>>
        node,
    const Locational<DoublyNodal<Elemental>>
        previous)
{
    node->link.previous = previous;
}

template <typename Elemental>
static inline void
UnsetNext(
    const Locational<SinglyNodal<Elemental>>
        node)
{
    node->link.node = 0;
}

template <typename Elemental>
static inline void
UnsetNext(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    node->link.next = 0;
}

template <typename Elemental>
static inline void
UnsetPrevious(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    node->link.previous = 0;
}

template <typename Elemental>
static inline void
ConnectNext(
    const Locational<SinglyNodal<Elemental>>
        first,
    const Locational<SinglyNodal<Elemental>>
        second)
{
    SetNext(first, second);
}

template <typename Elemental>
static inline void
ConnectNext(
    const Locational<DoublyNodal<Elemental>>
        first,
    const Locational<DoublyNodal<Elemental>>
        second)
{
    SetNext(first, second);
    if (second)
        SetPrevious(second, first);
}

template <typename Elemental>
static inline void
ConnectPrevious(
    const Locational<DoublyNodal<Elemental>>
        first,
    const Locational<DoublyNodal<Elemental>>
        second)
{
    SetPrevious(first, second);
    if (second)
        SetNext(second, first);
}

template <typename Elemental>
static inline void
DisconnectNext(
    const Locational<SinglyNodal<Elemental>>
        node)
{
    UnsetNext(node);
}

template <typename Elemental>
static inline void
DisconnectNext(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    if (GetNext(node)) {
        UnsetPrevious(GetNext(node));
        UnsetNext(node);
    }
}

template <typename Elemental>
static inline void
DisconnectPrevious(
    const Locational<DoublyNodal<Elemental>>
        node)
{
    if (GetPrevious(node)) {
        UnsetNext(GetPrevious(node));
        UnsetPrevious(node);
    }
}

template <
    typename Natural,
    typename Elemental>
static inline Locational<SinglyNodal<Elemental>>
GetFirst(
    Referential<const SinglyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list.first;
}

template <
    typename Natural,
    typename Elemental>
static inline Locational<DoublyNodal<Elemental>>
GetFirst(
    Referential<const DoublyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list.first;
}

template <
    typename Natural,
    typename Elemental>
static inline Locational<SinglyNodal<Elemental>>
GetLast(
    Referential<const SinglyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list.last;
}

template <
    typename Natural,
    typename Elemental>
static inline Locational<DoublyNodal<Elemental>>
GetLast(
    Referential<const DoublyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list.last;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Natural
Account(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list.count;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>>
        GetSubsequent>
static inline Natural
Count(
    Referential<const Junctive<Connective, Natural, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural count;
    count = 0;
    current = position.at;
    while (GetSubsequent(current)) {
        count++;
        current = GetSubsequent(current);
    }
    return count;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsEqual(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    return base.at == relative.at;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsNotEqual(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    return base.at != relative.at;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsGreater(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    current = GetNext(relative.at);
    while (current) {
        if (current == relative.at)
            return true;
        current = GetNext(current);
    }
    return false;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsLesser(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    current = GetNext(base.at);
    while (current) {
        if (current == relative.at)
            return true;
        current = GetNext(current);
    }
    return false;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsNotLesser(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    current = relative.at;
    while (current) {
        if (current == relative.at)
            return true;
        current = GetNext(current);
    }
    return false;
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsNotGreater(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    current = base.at;
    while (current) {
        if (current == relative.at)
            return true;
        current = GetNext(current);
    }
    return false;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Referential<Junctive<Connective, Natural, Elemental>>
Initialize(
    Referential<Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return list = InitializedList<Connective, Natural, Elemental>;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Referential<Junctive<Connective, Natural, Elemental>>
IntegrateNodes(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Locational<Nodal<Connective, Elemental>>
        nodes,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    Natural offset;
    if (count < 1)
        return list;
    for (offset = 1; offset < count; offset++)
        ConnectNext(nodes + offset - 1, nodes + offset);
    ConnectNext(nodes + count - 1, list.unused);
    list.unused = nodes;
    list.total += count;
    return list;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Natural
        Count>
static inline Referential<Junctive<Connective, Natural, Elemental>>
IntegrateNodes(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Nodal<Connective, Elemental>[Count]>
        nodes)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return IntegrateNodes(list, nodes, Count);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline bool
RemoveAll(
    Referential<Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    bool actioned = false;
    if (list.last) {
        ConnectNext(list.last, list.unused);
        list.unused = list.first;
        actioned = true;
    }
    list.first = list.last = 0;
    list.count = 0;
    return actioned;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Locational<Nodal<Connective, Elemental>>
Reclaim(
    Referential<Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational result;
    result = list.unused;
    if (result)
        list.unused = GetNext(result);
    return result;
}

// Returns false if deallocate returned false to prevent infinite loops.
// Verification of memory cleanup can be achieved by sampling the total
// node counts before and after the call to this function.
template <
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
DeleteOneNode(
    Referential<SinglyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational next;
    if (!list.unused)
        return false;
    next = GetNext(list.unused);
    if (!Adjunct.deallocate(list, list.unused))
        return false;
    list.unused = next;
    return list.unused;
}

// Returns false if deallocate returned false to prevent infinite loops.
// Verification of memory cleanup can be achieved by sampling the total
// node counts before and after the call to this function.
template <
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
DeleteOneNode(
    Referential<DoublyJunctive<Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<DoublyNodal<Elemental>>;
    NodeLocational next;
    if (!list.unused)
        return false;
    next = GetNext(list.unused);
    if (!Adjunct.deallocate(list, list.unused))
        return false;
    list.unused = next;
    if (next)
        UnsetPrevious(next);
    return list.unused;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Locational<Nodal<Connective, Elemental>>
AllocateNothing(
    Referential<Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return 0;
}

template <
    typename Connective,
    typename Disclaimable,
    typename Natural,
    typename Elemental,
    Referential<const Allocative<DefaultClaimable<Nodal<Connective, Elemental>>, Disclaimable>> Allocator>
static inline Locational<Nodal<Connective, Elemental>>
AllocateDefault(
    Referential<Junctive<Connective, Natural, Elemental>>
        list)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational result;
    Allocator.claim(result);
    if (result)
        list.total++;
    return result;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline bool
DeallocateNothing(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Locational<Nodal<Connective, Elemental>>>
        node)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return false;
}

template <
    typename Connective,
    typename Claimable,
    typename Natural,
    typename Elemental,
    Referential<const Allocative<Claimable, DefaultDisclaimable<Nodal<Connective, Elemental>>>> Allocator>
static inline bool
DeallocateDefault(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Locational<Nodal<Connective, Elemental>>>
        node)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (node) {
        Allocator.disclaim(node);
        list.total--;
        return true;
    }
    return false;
}

template <
    typename Connective,
    typename Disclaimable,
    typename Natural,
    typename Elemental,
    Referential<const Allocative<DefaultClaimable<Nodal<Connective, Elemental>>, Disclaimable>> Allocator>
static inline Locational<Nodal<Connective, Elemental>>
ProclaimDefault(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational result;
    result = Reclaim(list);
    if (!result) {
        Allocator.claim(result);
        if (!result)
            return 0;
        list.total++;
    }
    result->element = value;
    return result;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Locational<Nodal<Connective, Elemental>>
ProclaimCyclic(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational result;
    result = Reclaim(list);
    if (result)
        result->element = value;
    return result;
}

template <
    typename Disclaimable,
    typename Natural,
    typename Elemental,
    Referential<const Allocative<CopyClaimable<SinglyNodal<Elemental>>, Disclaimable>> Allocator>
static inline Locational<SinglyNodal<Elemental>>
ProclaimCopy(
    Referential<SinglyJunctive<Natural, Elemental>>
        list,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    const SinglyNodal<Elemental> copy = { { 0 }, value };
    NodeLocational result;
    Allocator.claim(result, copy);
    if (result)
        list.total++;
    return result;
}

template <
    typename Disclaimable,
    typename Natural,
    typename Elemental,
    Referential<const Allocative<CopyClaimable<DoublyNodal<Elemental>>, Disclaimable>> Allocator>
static inline Locational<DoublyNodal<Elemental>>
ProclaimCopy(
    Referential<DoublyJunctive<Natural, Elemental>>
        list,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<DoublyNodal<Elemental>>;
    const DoublyNodal<Elemental> copy = { { 0, 0 }, value };
    NodeLocational result;
    Allocator.claim(result, copy);
    if (result)
        list.total++;
    return result;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<const Adjunctive<Connective, Natural, Elemental>> Adjunct>
static inline bool
Instantiate(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational result;
    while (list.total - list.count < count) {
        result = Adjunct.allocate(list);
        if (!result)
            return false;
        ConnectNext(result, list.unused);
        list.unused = result;
    }
    return true;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline bool
Contains(
    Referential<const Junctive<Connective, Natural, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    current = list.first;
    while (current) {
        if (current == position.at)
            return true;
        current = GetNext(current);
    }
    return false;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Conferential<const Elemental>
GoRead(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
    using ::location::Deter;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& DeterElement = Deter<Elemental>;
    return DeterElement(position.at->element);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Conferential<Elemental>
GoWrite(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& ConferElement = Confer<Elemental>;
    return ConferElement(position.at->element);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Original<Connective, Natural, Elemental>> GetOrigin,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
BeginReadScale(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = GetOrigin(list);
    for (index = 0; index < count; index++)
        current = GetSubsequent(current);
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Original<Connective, Natural, Elemental>> GetOrigin,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
BeginWriteScale(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = GetOrigin(list);
    for (index = 0; index < count; index++)
        current = GetSubsequent(current);
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Original<Connective, Natural, Elemental>> GetOrigin,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline bool
DirectionBegins(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = GetOrigin(list);
    if (!current)
        return false;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(current);
        if (!current)
            return false;
    }
    return true;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
TraverseReadScale(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = position.at;
    for (index = 0; index < count; index++)
        current = GetSubsequent(current);
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
TraverseWriteScale(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = position.at;
    for (index = 0; index < count; index++)
        current = GetSubsequent(current);
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline bool
DirectionTraverses(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
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
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = position.at;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(current);
        if (!current)
            return false;
    }
    return true;
}

template <
    typename Natural,
    typename Elemental>
constexpr SinglyAdjunctive<Natural, Elemental>
    DefaultNewSingleAdjunct = {
        AllocateDefault<SinglyLinked<Elemental>, DefaultDisclaimable<SinglyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<SinglyNodal<Elemental>>>,
        DeallocateDefault<SinglyLinked<Elemental>, DefaultClaimable<SinglyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<SinglyNodal<Elemental>>>,
        ProclaimDefault<SinglyLinked<Elemental>, DefaultDisclaimable<SinglyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<SinglyNodal<Elemental>>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr DoublyAdjunctive<Natural, Elemental>
    DefaultNewDoubleAdjunct = {
        AllocateDefault<DoublyLinked<Elemental>, DefaultDisclaimable<DoublyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<DoublyNodal<Elemental>>>,
        DeallocateDefault<DoublyLinked<Elemental>, DefaultClaimable<DoublyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<DoublyNodal<Elemental>>>,
        ProclaimDefault<DoublyLinked<Elemental>, DefaultDisclaimable<DoublyNodal<Elemental>>, Natural, Elemental, FastDefaultNew<DoublyNodal<Elemental>>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr SinglyAdjunctive<Natural, Elemental>
    DefaultStaticSingleAdjunct = {
        AllocateNothing<SinglyLinked<Elemental>, Natural, Elemental>,
        DeallocateNothing<SinglyLinked<Elemental>, Natural, Elemental>,
        ProclaimCyclic<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr DoublyAdjunctive<Natural, Elemental>
    DefaultStaticDoubleAdjunct = {
        AllocateNothing<DoublyLinked<Elemental>, Natural, Elemental>,
        DeallocateNothing<DoublyLinked<Elemental>, Natural, Elemental>,
        ProclaimCyclic<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr SinglyAdjunctive<Natural, Elemental>
    CopyNewSingleAdjunct = {
        AllocateNothing<SinglyLinked<Elemental>, Natural, Elemental>,
        DeallocateDefault<SinglyLinked<Elemental>, CopyClaimable<SinglyNodal<Elemental>>, Natural, Elemental, FastCopyNew<SinglyNodal<Elemental>>>,
        ProclaimCopy<DefaultDisclaimable<SinglyNodal<Elemental>>, Natural, Elemental, FastCopyNew<SinglyNodal<Elemental>>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr DoublyAdjunctive<Natural, Elemental>
    CopyNewDoubleAdjunct = {
        AllocateNothing<DoublyLinked<Elemental>, Natural, Elemental>,
        DeallocateDefault<DoublyLinked<Elemental>, CopyClaimable<DoublyNodal<Elemental>>, Natural, Elemental, FastCopyNew<DoublyNodal<Elemental>>>,
        ProclaimCopy<DefaultDisclaimable<DoublyNodal<Elemental>>, Natural, Elemental, FastCopyNew<DoublyNodal<Elemental>>>
    };

template <typename Elemental>
constexpr Equative<SinglyPositional<Elemental>>
    SingleEquality = {
        IsEqual<SinglyLinked<Elemental>, Elemental>,
        IsNotEqual<SinglyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Equative<DoublyPositional<Elemental>>
    DoubleEquality = {
        IsEqual<DoublyLinked<Elemental>, Elemental>,
        IsNotEqual<DoublyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Relational<SinglyPositional<Elemental>>
    SingleRelation = {
        IsLesser<SinglyLinked<Elemental>, Elemental>,
        IsGreater<SinglyLinked<Elemental>, Elemental>,
        IsNotGreater<SinglyLinked<Elemental>, Elemental>,
        IsNotLesser<SinglyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Relational<DoublyPositional<Elemental>>
    DoubleRelation = {
        IsLesser<DoublyLinked<Elemental>, Elemental>,
        IsGreater<DoublyLinked<Elemental>, Elemental>,
        IsNotGreater<DoublyLinked<Elemental>, Elemental>,
        IsNotLesser<DoublyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Comparative<SinglyPositional<Elemental>>
    SingleComparison = {
        SingleEquality<Elemental>,
        SingleRelation<Elemental>
    };

template <typename Elemental>
constexpr Comparative<DoublyPositional<Elemental>>
    DoubleComparison = {
        DoubleEquality<Elemental>,
        DoubleRelation<Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, const Elemental>
    ReadSingleVector = {
        SingleComparison<Elemental>,
        Contains<SinglyLinked<Elemental>, Natural, Elemental>,
        GoRead<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, const Elemental>
    ReadDoubleVector = {
        DoubleComparison<Elemental>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        GoRead<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Elemental>
    WriteSingleVector = {
        SingleComparison<Elemental>,
        Contains<SinglyLinked<Elemental>, Natural, Elemental>,
        GoWrite<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Elemental>
    WriteDoubleVector = {
        DoubleComparison<Elemental>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        GoWrite<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, const Elemental>
    ReadIncrementSingleScale = {
        SingleComparison<Elemental>,
        BeginReadScale<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseReadScale<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoRead<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadIncrementDoubleScale = {
        DoubleComparison<Elemental>,
        BeginReadScale<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseReadScale<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoRead<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
    WriteIncrementSingleScale = {
        SingleComparison<Elemental>,
        BeginWriteScale<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseWriteScale<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoWrite<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteIncrementDoubleScale = {
        DoubleComparison<Elemental>,
        BeginWriteScale<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseWriteScale<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoWrite<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadDecrementDoubleScale = {
        DoubleComparison<Elemental>,
        BeginReadScale<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        TraverseReadScale<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        GoRead<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteDecrementDoubleScale = {
        DoubleComparison<Elemental>,
        BeginWriteScale<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        TraverseWriteScale<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        GoWrite<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Lineal<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadDoubleLiner = {
        ReadIncrementDoubleScale<Natural, Elemental>,
        ReadDecrementDoubleScale<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Lineal<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteDoubleLiner = {
        WriteIncrementDoubleScale<Natural, Elemental>,
        WriteDecrementDoubleScale<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, const Elemental>
    ReadIncrementSingleDirection = {
        ReadIncrementSingleScale<Natural, Elemental>,
        DirectionBegins<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraverses<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        Contains<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Count<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadIncrementDoubleDirection = {
        ReadIncrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraverses<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
    WriteIncrementSingleDirection = {
        WriteIncrementSingleScale<Natural, Elemental>,
        DirectionBegins<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraverses<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        Contains<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Count<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteIncrementDoubleDirection = {
        WriteIncrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraverses<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadDecrementDoubleDirection = {
        ReadDecrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        DirectionTraverses<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteDecrementDoubleDirection = {
        WriteDecrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        DirectionTraverses<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        Contains<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Axial<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    ReadDoubleAxis = {
        ReadIncrementDoubleDirection<Natural, Elemental>,
        ReadDecrementDoubleDirection<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Axial<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    WriteDoubleAxis = {
        WriteIncrementDoubleDirection<Natural, Elemental>,
        WriteDecrementDoubleDirection<Natural, Elemental>
    };

}

#endif
