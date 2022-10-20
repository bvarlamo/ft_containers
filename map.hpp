#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "ft.hpp"
#include <memory>
#include <functional>

namespace	ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T>>
	> class	map
	{
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const Key, T>					value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;
		typedef pointer									iterator;
		typedef const_iterator							const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		template <class Key, class T, class Compare, class Alloc>
		class map<Key,T,Compare,Alloc>::value_compare : public binary_function<value_type, value_type, bool>
		{
			friend class map;

			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

			public:
				typedef bool 			result_type;
				typedef value_type 		first_argument_type;
				typedef value_type 		second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		}
		
	};
}

#endif