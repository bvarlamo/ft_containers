#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "trees.hpp"
#include "utils.hpp"

namespace ft
{

	template<
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key>
	> class set
	{
		public:

			typedef Key																			key_type;
			typedef Key																			value_type;
			typedef std::size_t																	size_type;
			typedef std::ptrdiff_t																difference_type;
			typedef Compare																		key_compare;
			typedef Compare																		value_compare;
			typedef Allocator																	allocator_type;
			typedef value_type&																	reference;
			typedef const value_type&															const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef typename ft::trees<value_type, Compare, Allocator>::iterator					iterator;
			typedef typename ft::trees<value_type, Compare, Allocator>::const_iterator			const_iterator;
			typedef typename ft::trees<value_type, Compare, Allocator>::reverse_iterator			reverse_iterator;
			typedef typename ft::trees<value_type, Compare, Allocator>::const_reverse_iterator	const_reverse_iterator;

		private:
			ft::trees<value_type, Compare, Allocator>							_tree;
			allocator_type	_alloc;
			key_compare		_comp;

		public:

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
			}

			template <class InputIterator>  
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				InputIterator tmp = first;
				while (tmp != last)
				{
					_tree.insert(*tmp);
					tmp++;
				}
			}

			set (const set& x)
			{
				_tree.insert(x.begin(), x.end());
			}

			~set()
			{

			}

			set& operator= (const set& x)
			{
				if (&x == this)
					return *this;
				clear();
				_tree.insert(x.begin(), x.end());
				return *this;
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

			bool empty() const
			{
				return (_tree.empty());
			}

			size_type size() const
			{
				return (_tree.size());
			}

			size_type max_size() const
			{
				return std::min<size_type>( _tree.max_size(), std::numeric_limits<difference_type >::max());
			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				return (_tree.insert(val));
			}

			iterator insert (iterator position, const value_type& val)
			{
				return (_tree.insert(position, val));
			}

			template <class InputIterator>  void insert (InputIterator first, InputIterator last)
			{
				_tree.insert(first, last);
			}

			void erase (iterator position)
			{
				_tree.erase(*position);
			}

			size_type erase (const value_type& val)
			{
				return (_tree.erase(val));
			}

			void erase (iterator first, iterator last)
			{
				_tree.erase(first, last);
			}

			void swap (set& x)
			{
				std::swap(_alloc, x._alloc);
				std::swap(_comp, x._comp);
				_tree.swap(x._tree);
			}

			void clear()
			{
				_tree.clear();
			}

			key_compare key_comp() const
			{
				return (key_compare());
			}

			value_compare value_comp() const
			{
				return (value_compare(key_compare()));
			}

			iterator find (const value_type& val) const
			{
				return (_tree.find(val));
			}

			size_type count (const value_type& val) const
			{
				return (_tree.count(val));
			}

			iterator lower_bound (const value_type& val) const
			{
				return (_tree.lower_bound(val));
			}

			iterator upper_bound (const value_type& val) const
			{
				return (_tree.upper_bound(val));
			}

			ft::pair<iterator,iterator> equal_range (const value_type& val) const
			{
				const_iterator low = _tree.lower_bound(val);
				const_iterator up = _tree.upper_bound(val);
				return (ft::pair<const_iterator, const_iterator>(low, up));
			}

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

	};

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

}



#endif