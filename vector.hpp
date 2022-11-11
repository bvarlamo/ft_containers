/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:28:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/11/11 15:17:28 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils.hpp"
#include "iterator.hpp"
#include <iterator>
#include <iostream>

namespace	ft
{
	template <class T, class Allocator = std::allocator <T> >
	class	vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::random_access_iterator<pointer>				iterator;
			typedef ft::random_const_access_iterator<pointer>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		private:
			pointer											_data;
			pointer											_end;
			std::size_t									_size;
			std::size_t									_capacity;
			allocator_type								_alloc;
			
		public:
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_data = _alloc.allocate(0);
				// _end = end();
				_size = 0;
				_capacity = 0;
			}

			vector(const vector& x)
			{
				_alloc = x.get_allocator();
				_data = _alloc.allocate(x.capacity());
				_end = _data;
				_size = x.size();
				_capacity = x.capacity();
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_end[i], x._data[i]);
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_data = _alloc.allocate(n);
				_size = 0;
				_capacity = n;
				_end = _data;
				while (n--)
				{
					_alloc.construct(_end, val);
					_size++;
					_end++;
				}
			}
			
			template <class InputIterator> 
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integrals<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				_alloc = alloc;
				difference_type n = 0;
				while (&first[n] != last)
				{
					n++;
				}
				_data = _alloc.allocate(n);
				_size = 0;
				_capacity = n;
				_end = _data;
				while (n--)
				{
					_alloc.construct(_end, *first);
					_end++;
					first++;
					_size++;
				}

				// range constructer
			}

			~vector()
			{
				if (_data)
					_alloc.deallocate(_data, _size);
			}

			vector& operator=(const vector& x)
			{
				_alloc.destroy(_data);
				_alloc.deallocate(_data, _capacity);
				_alloc = x.get_allocator();
				_data = _alloc.allocate(_capacity);
				_end = _data;
				_size = x.size();
				_capacity = x.capacity();
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_end[i], x._data[i]);
				return *this;
			}
	
			void push_back(const T& value)
			{
				insert(end(), value);
				// Add 'value' to the end
			}

			iterator insert(const_iterator it, const T& value)
			{
				difference_type index = it - begin();
				if (_size == _capacity)
				{
					_capacity = (_capacity) ? (_capacity * 2) : 1;
					T* new_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						new_data[i] = _data[i];
					size_type new_size = _size;
					size_type new_capacity = _capacity;
					if (_data)
						_alloc.deallocate(_data, _size);
					_data = new_data;
					_size = new_size;
					_capacity = new_capacity;
				}
				for (difference_type i = _size - 1; i >= index; --i)
					_alloc.construct(&_data[i + 1], _data[i]);
				_data[index] = value;
				_size++;
				return (&_data[index]);
			}

			iterator insert( const_iterator pos, size_type count, const T& value )
			{
				difference_type index = pos - begin();
				if (count == 0)
					return (iterator)pos;
				if (count > this->max_size())
					throw (std::length_error("count to big"));
				else
				{
					if (_size + count > _capacity)
						reserve(_size + count);
					while (count > 0)
					{
						_end = _data;
						insert(&_end[index], value);
						index++;
						count--;
					}
				}
				return &_data[index - count];
			}
			
			template< class InputIt >
			iterator insert( const_iterator pos, InputIt first, InputIt last, 
			typename ft::enable_if<!ft::is_integrals<InputIt>::value, InputIt>::type* = nullptr)
			{
				if (first == last)
					return (iterator)pos;
				difference_type index = pos - begin();
				InputIt it = first;
				size_type i = 0;
				while (&it[i] != last)
					i++;
				if (_size + i > _capacity)
					reserve(_size + i);
				while (first != last)
				{
					_end = _data;
					insert(&_end[index], *first);
					index++;
					first++;
				}
				return &_data[pos - begin()];
			}
			
			iterator begin(void)
			{
				iterator it = _data;
				return (it);
			}

			const_iterator begin(void) const
			{
				const_iterator it = _data;
				return (it);
			}

			iterator end(void)
			{
				iterator it = &_data[_size];
				return (it);
			}

			const_iterator end(void) const
			{
				const_iterator it = &_data[_size];
				return (it);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator it(end());
				return(it);
			}

			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator it(end() - 1);
				return(it);
			}
			
			reverse_iterator rend()
			{
				reverse_iterator it(begin());
				return (it);
			}

			const_reverse_iterator rend() const
			{
				const_reverse_iterator it(begin());
				return (it);
			}

			size_type size() const
			{
				return(_size);
			}

			size_type   max_size(void) const
			{
				return allocator_type().max_size(); 
			}

			size_type capacity() const
			{
				return(_capacity);
			}

			reference operator[]( size_type pos )
			{
				iterator it = _data;
				for (size_type i = 0; i != pos; i++)
					it++;
				return (*it);
			}
	
			void resize (size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw (std::length_error("vector::resize"));
				else if (n < this->size())
				{
					while (this->size() > n)
					{
						_end = end();
						--_end;
						_alloc.destroy(_end);
						_size--;
					}
				}
				else
				{
					reserve(n);
					_end = _data;
					insert(&_end[_size], n - _size, val);
				}
			}

			bool	empty() const
			{
				return (!_size);
			}

			void	reserve (size_type n)
			{
				if (n > _capacity)
				{
					T* new_data = _alloc.allocate(n);
					for (size_type i = 0; i < _size; ++i)
						new_data[i] = _data[i];
					size_type new_size = _size;
					size_type new_capacity = n;
					if (_data)
						_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_size = new_size;
					_capacity = new_capacity;
				}
			}

			void	shrink_to_fit()
			{
				if (_size < _capacity)
				{
					T* new_data = _alloc.allocate(_size);
					for (size_type i = 0; i < _size; ++i)
						new_data[i] = _data[i];
					size_type new_size = _size;
					size_type new_capacity = _size;
					if (_data)
						_alloc.deallocate(_data, _size);
					_data = new_data;
					_size = new_size;
					_capacity = new_capacity;
				}
			}

			reference 	at (size_type n)
			{
				reference it = _data[n];
				return(it);
			}

			const_reference 	at (size_type n) const
			{
				const_reference it = _data[n];
				return(it);
			}

			reference	front()
			{
				reference it = _data[0];
				return (it);
			}

			const_reference	front() const
			{
				const_reference it = _data[0];
				return (it);
			}
			reference	back()
			{
				reference it = _data[_size - 1];
				return (it);
			}

			const_reference	back() const
			{
				const_reference it = _data[_size - 1];
				return (it);
			}

			value_type*	data()
			{
				value_type	*it = _data;
				return (it);
			}

			const	value_type*	data() const
			{
				const	value_type it = _data;
				return (it);
			}

			template <class InputIterator>
			void	assign (InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integrals<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				clear();
				InputIterator it = first;
				size_type i = 0;
				_end = _data;
				while (it != last)
				{
					if (it == &_end[i] || last == &_end[i])
						return ;
					i++;
					it++;
				}
				if (_capacity < i)
				{
					_alloc.deallocate(_data, _capacity);
					_data = _alloc.allocate(i);
					_capacity = i;
				}
				_end = _data;
				while (first != last)
				{
					_alloc.construct(_end, *first);
					_end++;
					first++;
					i--;
					_size++;
				}
			}

			void	assign (size_type n, const value_type& var)
			{
				clear();
				if (n == 0)
					return ;
				if (_capacity < n)
				{
					_alloc.deallocate(_data, _capacity);
					_data = _alloc.allocate(n);
					_capacity = n;
				}
				_end = _data;
				while (n)
				{
					_alloc.construct(_end, var);
					_end++;
					n--;
					_size++;
				}
			}

			void	clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_data[i]);
				_size = 0;
			}

			void	pop_back()
			{
				_alloc.destroy(&_data[_size - 1]);
				_size--;
			}

			iterator	erase (iterator position)
			{
				iterator it = begin();
				size_type i = 0;
				while (it != position)
				{
					i++;
					it++;
				}
				_alloc.destroy(&_data[i]);
				while ((i + 1) < _size)
				{
					_data[i] = _data[i + 1];
					i++;
				}
				_alloc.destroy(&_data[i]);
				_size--;
				return (it);
			}

			iterator	erase (iterator first, iterator last)
			{
				iterator it = begin();
				size_type i = 0;
				while (it != first)
				{
					i++;
					it++;
				}
				size_type y = i;
				while (first != last)
				{
					_alloc.destroy(&_data[i]);
					i++;
					first++;
				}
				while (i < _size)
				{
					_data[y] = _data[i];
					i++;
					y++;
				}
				_size -= i - y;
				while (y < _size)
					_alloc.destroy(&_data[y]);
				return (it);
			}

			void	swap (vector& x)
			{
				T*	tmp_data = x._data;
				size_type	tmp_s = x._size;
				size_type	tmp_c = x._capacity;

				x._data = _data;
				x._size = _size;
				x._capacity = _capacity;

				_data = tmp_data;
				_size = tmp_s;
				_capacity = tmp_c;
			}

			allocator_type	get_allocator() const
			{
				allocator_type it = _alloc;
				return (it);
			}
	};

	template <class T, class Alloc>  
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>  
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
		else
		{
			bool	tmp = ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			return (((tmp) ? false : true));
		}
	}

	template <class T, class Alloc>  
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>  
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>  
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs <= rhs)
			return (false);
		return (true);
	}

	template <class T, class Alloc>  
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs > rhs || lhs == rhs)
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>
	void	swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
};

#endif