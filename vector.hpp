/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:28:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/11/16 11:29:57 by bvarlamo         ###   ########.fr       */
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
			typedef ft::random_access_iterator<value_type>		iterator;
			typedef ft::random_access_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		private:
			pointer											_data;
			pointer											_end;
			std::size_t									_size;
			std::size_t									_capacity;
			allocator_type								_alloc;

			template<class InputIt>
			bool validate_iterator_values(InputIt first, InputIt last, size_t range) 
			{
				pointer reserved_buffer;
				reserved_buffer = _alloc.allocate(range);
				bool result = true;
				size_t i = 0;

				for (;first != last; ++first, ++i) {
					try { reserved_buffer[i] = *first; }
					catch (...) { result = false; break; }
				}
				_alloc.deallocate(reserved_buffer, range);
				return result;
			}
			
		public:
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_data = _alloc.allocate(0);
				_end = _data;
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
			typename ft::enable_if<!ft::is_integrals<InputIterator>::value, InputIterator>::type* = 0)
			{
				_alloc = alloc;
				InputIterator it = first;
				_size = 0;
				while (it != last)
				{
					it++;
					_size++;
				}
				_capacity = _size;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&_data[i], *first);
					first++;
				}
			}

			~vector()
			{
				if (_data)
					_alloc.deallocate(_data, _capacity);
			}

			vector& operator=(const vector& x)
			{
				
				clear();
				_alloc.deallocate(_data, _capacity);
				_data = _alloc.allocate(x.capacity());
				_end = _data;
				_size = x.size();
				_capacity = x.capacity();
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_end[i], x._data[i]);
				return *this;
			}
	
			void push_back(const T& value)
			{
				if (_size >= _capacity)
				{
					_capacity = (_capacity) ? (_capacity * 2) : 1;
					T* new_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(&new_data[i], _data[i]);
					size_type new_size = _size;
					size_type new_capacity = _capacity;
					if (_data)
						_alloc.deallocate(_data, _size);
					_data = new_data;
					_size = new_size;
					_capacity = new_capacity;
				}
				_alloc.construct(&_data[_size], value);
				_size++;
			}

			iterator insert(const_iterator it, const T& value)
			{
				if (it < begin() || it > end())
					throw std::logic_error("vector");
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
				return (iterator(&_data[index]));
			}

			iterator insert( const_iterator pos, size_type count, const T& value )
			{
				difference_type index = pos - begin();
				_end = _data;
				if (count == 0)
					return (iterator(&_end[index]));
				if (count < 0 || count > this->max_size())
					throw (std::length_error("wrong count"));
				else
				{
					if (_size + count > _capacity)
					{
						// size_type c = _capacity;
						// while (c < (_size + count))
						// 	c = (c) ? (c * 2) : 1;
						reserve(_size + count);
					}
					size_type i = (static_cast<size_type> (index));
					size_type s = _size + count - 1;
					size_type t = _size - i;
					size_type ss = _size - 1;
					while (t > 0)
					{
						_alloc.construct(&_data[s], _data[ss]);
						s--;
						t--;
						ss--;
					}
					while (count > 0)
					{
						_alloc.construct(&_data[index], value);
						index++;
						count--;
						_size++;
					}
				}
				return (iterator(&_data[index - count]));
			}
			
			template< class InputIt >
			iterator insert( const_iterator pos, InputIt first, InputIt last, 
			typename ft::enable_if<!ft::is_integrals<InputIt>::value, InputIt>::type* = nullptr)
			{
				// size_t range_size = 0;
				// InputIt ii = first;
				// while (ii != last)
				// {
				// 	range_size++;
				// 	ii++;
				// }
				// if (!validate_iterator_values(first, last, range_size))
				// 	throw std::exception();
				if (pos < begin() || pos > end())
					throw std::logic_error("vector");
				difference_type index = pos - begin();
				_end = _data;
				if (first == last)
					return iterator(&_end[index]);
				InputIt it = first;
				size_type i = 0;
				while (it != last)
				{
					it++;
					i++;
				}
				if (_size + i > _capacity)
				{
					// size_type c = _capacity;
					// while (c < (_size + i))
					// 	c = (c) ? (c * 2) : 1;
					reserve(_size + i);
				}
				size_type in = (static_cast<size_type> (index));
				size_type s = _size + i - 1;
				size_type t = _size - in;
				size_type ss = _size - 1;
				while (t > 0)
				{
					_alloc.construct(&_data[s], _data[ss]);
					s--;
					t--;
					ss--;
				}
				it = first;
				while (it != last)
				{
					_alloc.construct(&_data[index], *it);
					index++;
					it++;
					_size++;
				}
				return (iterator(&_data[pos - begin()]));
			}
			
			iterator begin(void)
			{
				iterator it(_data);
				return (it);
			}

			const_iterator begin(void) const
			{
				const_iterator it(_data);
				return (it);
			}

			iterator end(void)
			{
				iterator it(&_data[_size]);
				return (it);
			}

			const_iterator end(void) const
			{
				const_iterator it(&_data[_size]);
				return (it);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator it(end());
				return(it);
			}

			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator it(end());
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
				iterator it(_data);
				for (size_type i = 0; i != pos; i++)
					it++;
				return (*it);
			}

			const_reference operator[]( size_type pos ) const
			{
				return (_data[pos]);
			}
	
			void resize (size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw (std::length_error("vector::resize"));
				else if (n < _size)
				{
					while (_size > n)
					{
						_size--;
						_alloc.destroy(&_data[_size]);
					}
				}
				else if (n > _size)
				{
					if (n > _capacity)
					{
						// size_type c = _capacity;
						// while (c < n)
						// 	c = (c) ? (c * 2) : 1;
						reserve(n);
					}
					while (_size < n)
					{
						_alloc.construct(&_data[_size], val);
						_size++;
					}
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
					pointer new_d = _alloc.allocate(n);
					size_type i = 0;
					while (i < _size)
					{
						_alloc.construct(&new_d[i], _data[i]);
						i++;
					}
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					_capacity = n;
					_data = new_d;
				}
			}

			void	shrink_to_fit()
			{
				if (_size < _capacity)
				{
					pointer new_data = _data;
					_data = _alloc.allocate(_size);
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(&_data[i], new_data[i]);
					size_type new_capacity = _size;
					if (_data)
						_alloc.deallocate(new_data, _capacity);
					_capacity = _size;
				}
			}

			reference 	at (size_type n)
			{
				if(n > _capacity)
					throw std::out_of_range("vector at out of range");
				reference it = _data[n];
				return(it);
			}

			const_reference 	at (size_type n) const
			{
				if(n > _capacity)
					throw std::out_of_range("vector at out of range");
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
				_size = 0;
				InputIterator it = first;
				size_type i = 0;
				while (it != last)
				{
					i++;
					it++;
				}
				if (_capacity < i)
				{
					reserve(i);
				}
				while (first != last)
				{
					_alloc.construct(&_data[_size], *first);
					first++;
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
				std::swap(_data, x._data);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
				// T*	tmp_data = x._data;
				// size_type	tmp_s = x._size;
				// size_type	tmp_c = x._capacity;
				// allocator_type tall = x._alloc;

				// x._data = _data;
				// x._size = _size;
				// x._capacity = _capacity;
				// x._alloc = _alloc;

				// _data = tmp_data;
				// _size = tmp_s;
				// _capacity = tmp_c;
				// _alloc = tall;
			}

			allocator_type	get_allocator() const
			{
				allocator_type it = _alloc;
				return (it);
			}
	};

	template <class T, class Alloc>  
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>  
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
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
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>  
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>  
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs <= rhs)
			return (false);
		return (true);
	}

	template <class T, class Alloc>  
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs > rhs || lhs == rhs)
			return (true);
		else
			return (false);
	}

	template <class T, class Alloc>
	void	swap (ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
	{
		x.swap(y);
	}
};

#endif