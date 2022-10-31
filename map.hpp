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
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class	map
	{
		public:

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;


		private:

			class value_compare : public std::binary_function<value_type, value_type, bool>
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
			};
			struct	node
			{
				value_type*		data;
				bool			isred;
				allocator_type _alloc;

				node*		left;
				node*		right;
				node*		p;

				node(node* _p)
				{
					data = NULL;
					left = NULL;
					right = NULL;
					isred = false;
					p = _p;
				}

				node(allocator_type alloc, value_type _data, node* _p)
				{
					_alloc = alloc;
					data = alloc.allocate(1);
					alloc.construct(data, _data.first, _data.second);
					left = new node(&*this);
					right = new node(&*this);
					isred = false;
					p = _p;
				}

				~node()
				{
					if (data)
					{
						_alloc.destroy(data);
						_alloc.deallocate(data, 1);
					}
					if (left)
						delete left;
					if (right)
						delete right;
				}

			};

			node*			root;
			node**			current;
			size_type		_size;
			allocator_type	_alloc;
			key_compare		_comp;

		public:
			typedef ft::map_iterator<node, value_type, node>	iterator;
			typedef const iterator								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			void left_rotate(node* x)
			{
				node*	y = x->right;
				x->right = y->left;
				if (y->left && y->left->data != NULL)
					y->left->p = x;
				y->p = x->p;
				if (x->p== NULL)
					root = y;
				else if (x->p && x == x->p->left)
					x->p->left = y;
				else
					x->p->right = y;
				y->left = x;
				x->p = y;
			}

			void right_rotate(node* x)
			{
				node*	y = x->left;
				x->left = y->right;
				if (y->right && y->right->data != NULL)
					y->right->p = x;
				y->p = x->p;
				if (x->p == NULL)
					root = y;
				else if (x->p && x == x->p->right)
					x->p->right = y;
				else
					x->p->left = y;
				y->right = x;
				x->p = y;
			}

			node* insert_fixup(node* z)
			{
				node*	y;
				node*	tmp;
				tmp = z;
				while (tmp->p && tmp->p->isred)
				{
					if (tmp->p == tmp->p->p->left)
					{
						y = tmp->p->p->right;
						if (y->isred)
						{
							tmp->p->isred = false;
							y->isred = false;
							tmp->p->p->isred = true;
							tmp = tmp->p->p;
						}
						else
						{
							if (tmp == tmp->p->right)
							{
								tmp = tmp->p;
								left_rotate(tmp->p);
							}
							tmp->p->isred = false;
							if (tmp->p->p)
								tmp->p->p->isred = true;
							right_rotate(tmp->p->p);
						}
					}
					else 
					{
						y = tmp->p->p->left;
						if (y->isred)
						{
							tmp->p->isred = false;
							y->isred = false;
							tmp->p->p->isred = true;
							tmp = tmp->p->p;
						}
						else
						{
							if (tmp == tmp->p->left)
							{
								tmp = tmp->p;
								right_rotate(tmp->p);
							}
							tmp->p->isred = false;
							if (tmp->p->p)
								tmp->p->p->isred = true;
							left_rotate(tmp->p->p);
						}
					}
					root->isred = false;
				}
				return z;
			}

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				root = NULL;
				_size = 0;
				current = NULL;
			}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				_comp = comp;
				_alloc = alloc;
				root = NULL;
				_size = 0;
				current = NULL;
				InputIt tmp = first;
				while (tmp != last)
				{
					insert(*tmp);
					tmp++;
				}
			}

			map (const map& x)
			{
				_comp = x._comp;
				_alloc = x._alloc;
				root = NULL;
				_size = 0;
				current = NULL;
				insert(x.begin(), x.end());
			}
		
			iterator end()
			{
				current = &root;
				while ((*current) && (*current)->right)
					current = &(*current)->right;
				iterator tm((*current), root);
				return (tm);
			}

			iterator begin()
			{
				current = &root;
				while ((*current) && (*current)->left->data)
					current = &(*current)->left;
				iterator tm((*current), root);
				return (tm);
			}

			const_iterator end() const
			{
				node* tmp = root;
				while (tmp && tmp->left && tmp->right)
					tmp = tmp->right;
				iterator tm(tmp, root);
				const_iterator f(tm);
				return (f);
			}

			const_iterator begin() const
			{
				node* tmp = root;
				while (tmp && tmp->left && tmp->left->data)
					tmp = tmp->left;
				iterator tm(tmp, root);
				const_iterator f(tm);
				return (f);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator it(end());
				return (it);
			}

			reverse_iterator rend()
			{
				reverse_iterator it(begin());
				return (it);
			}

			~map()
			{
				if (root)
					delete root;
			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (root == NULL)
				{
					root = new node(_alloc, val, NULL);
					current = &root;
					root->isred = false;
					_size++;
					return (ft::pair<iterator, bool>(iterator((*current), root), true));
				}
				current = &root;
				node *p;
				while ((*current)->data != NULL)
				{
					p = *current;
					if ((*current)->data && (*current)->data->first == val.first)
						return(ft::pair<iterator, bool>((iterator((*current), root)), false));
					else if (value_compare(_comp).comp((*current)->data->first, val.first))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				delete *current;
				*current = new node(_alloc, val, p);
				(*current)->isred = true;
				node* tmp;
				tmp = insert_fixup((*current));
				current = &tmp;
				_size++;
				return (ft::pair<iterator, bool>((iterator((*current), root)), true));
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				InputIt tmp = first;
				while (tmp != last)
				{
					insert(*tmp);
					tmp++;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return (insert(val).first);
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			bool empty() const
			{
				return !_size;
			}

			mapped_type& operator[] (const key_type& k)
			{
				mapped_type *m = &((this->insert(ft::make_pair(k,mapped_type()))).first->second);
				return (*m);
			}

			mapped_type& at (const key_type& k)
			{
				current = &root;
				while ((*current)->data != NULL)
				{
					if ((*current)->data && (*current)->data->first == k)
						return((*current)->data->second);
					else if (value_compare(_comp).comp((*current)->data->first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				throw std::out_of_range("Dont have this key");
			}

			const mapped_type& at (const key_type& k) const
			{
				current = &root;
				while ((*current)->data != NULL)
				{
					if ((*current)->data && (*current)->data->first == k)
						return((*current)->data->second);
					else if (value_compare(_comp).comp((*current)->data->first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				throw std::out_of_range("Dont have this key");
			}

			void swap (map& x)
			{
				node* tmp = x.root;
				size_type tm = x._size;
				x.root = root;
				x._size = _size;
				root = tmp;
				_size = tm;
			}

			void clear()
			{
				if (root)
					delete root;
				root = NULL;
				_size = 0;
			}

			map& operator= (const map& x)
			{
				clear();
				if (&x == this)
					return *this;
				insert(x.begin(), x.end());
				return *this;
			}

			size_type count( const Key& key ) const
			{
				node*	tmp = root;
				while (tmp->data != NULL)
				{
					if (tmp->data && tmp->data->first == key)
						return(1);
					else if (value_compare(_comp).comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return 0;
			}

			iterator find( const Key& key )
			{
				node* tmp = root;
				while (tmp->data != NULL)
				{
					if (tmp->data && tmp->data->first == key)
						return(iterator(tmp, root));
					else if (value_compare(_comp).comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return (end());
			}

			const_iterator find( const Key& key ) const
			{
				node* tmp = root;
				while (tmp->data != NULL)
				{
					if (tmp->data && tmp->data->first == key)
						return(const_iterator(tmp, root));
					else if (value_compare(_comp).comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return (end());
			}
	};

}
#endif