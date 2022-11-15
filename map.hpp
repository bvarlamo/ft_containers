#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "tree.hpp"
#include "utils.hpp"
#include "iterator.hpp"

namespace	ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class	map
	{

		public:

			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key, T>														value_type;
			typedef std::size_t																	size_type;
			typedef std::ptrdiff_t																difference_type;
			typedef Compare																		key_compare;
			typedef Allocator																	allocator_type;
			typedef value_type&																	reference;
			typedef const value_type&															const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef typename ft::tree<value_type, Compare, Allocator>::iterator					iterator;
			typedef typename ft::tree<value_type, Compare, Allocator>::const_iterator			const_iterator;
			typedef typename ft::tree<value_type, Compare, Allocator>::reverse_iterator			reverse_iterator;
			typedef typename ft::tree<value_type, Compare, Allocator>::const_reverse_iterator	const_reverse_iterator;

			private:
				ft::tree<value_type, Compare, Allocator>							_tree;
				allocator_type	_alloc;
				key_compare		_comp;

			public:

				class value_compare : public std::binary_function<value_type, value_type, bool>
				{
					friend class map<key_type, mapped_type, key_compare, Allocator>;

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
				};
		

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			}

			template< class InputIt >
			map( InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				InputIt tmp = first;
				while (tmp != last)
				{
					_tree.insert(*tmp);
					tmp++;
				}
			}

			map (const map& x)
			{
				_tree.insert(x.begin(), x.end());
			}
			~map()
			{

			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				return (_tree.insert(val));
			}

			size_type erase (const key_type& k)
			{
				return (_tree.erase(k));
			}

			void erase (iterator position)
			{
				_tree.erase(position->first);
			}

			void erase (iterator first, iterator last)
			{
				_tree.erase(first, last);
			}

			iterator begin()
			{
				return (_tree.begin());
			}

			const_iterator begin() const
			{
				const_iterator tmp = _tree.begin();
				return (tmp);
			}

			iterator end()
			{
				return (_tree.end());
			}

			const_iterator end() const
			{
				const_iterator tmp = _tree.end();
				return (tmp);
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				_tree.insert(first, last);
			}

			iterator insert (iterator position, const value_type& val)
			{
				return (_tree.insert(position, val));
			}

			size_type size() const
			{
				return (_tree.size());
			}


			bool empty() const
			{
				return (_tree.empty());
			}

			mapped_type& operator[] (const key_type& k)
			{
				mapped_type *m = &((_tree.insert(ft::make_pair(k,mapped_type()))).first->second);
				return (*m);
			}

			mapped_type& at (const key_type& k)
			{
				return (_tree.at(k));
			}

			const mapped_type& at (const key_type& k) const
			{
				return (_tree.at(k));
			}

			size_type max_size() const
			{
				return std::min<size_type>( _tree.max_size(), std::numeric_limits<difference_type >::max());
			}

			map& operator= (const map& x)
			{
				if (&x == this)
					return *this;
				clear();
				_tree.insert(x.begin(), x.end());
				return *this;
			}

			void clear()
			{
				_tree.clear();
			}

			size_type count( const Key& key ) const
			{
				return (_tree.count(key));
			}

			iterator find( const Key& key )
			{
				return (_tree.find(key));
			}

			const_iterator find( const Key& key ) const
			{
				return (_tree.find(key));
			}

			iterator lower_bound( const Key& key )
			{
				return (_tree.lower_bound(key));
			}

			const_iterator lower_bound( const Key& key ) const
			{
				return (_tree.lower_bound(key));
			}

			iterator upper_bound( const Key& key )
			{
				return (_tree.upper_bound(key));
			}

			const_iterator upper_bound( const Key& key ) const
			{
				return (_tree.upper_bound(key));
			}

			ft::pair<iterator,iterator> equal_range( const Key& key )
			{
				iterator low = _tree.lower_bound(key);
				iterator up = _tree.upper_bound(key);
				return (ft::pair<iterator, iterator>(low, up));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				const_iterator low = _tree.lower_bound(key);
				const_iterator up = _tree.upper_bound(key);
				return (ft::pair<const_iterator, const_iterator>(low, up));
			}

			key_compare key_comp() const
			{
				return (key_compare());
			}

			value_compare value_comp() const
			{
				return (value_compare(key_compare()));
			}

			void swap (map& x)
			{
				std::swap(_alloc, x._alloc);
				std::swap(_comp, x._comp);
				_tree.swap(x._tree);
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}
}

#endif