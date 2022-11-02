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

		private:
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
			typedef ft::map_iterator<node, value_type, node>			iterator;
			typedef ft::map_const_iterator<node, value_type, node>		const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			
			void transplant(node* del, node* sib)
			{
				if (del->p == NULL)
					root = sib;
				else if (del == del->p->left)
					del->p->left = sib;
				else
					del->p->right = sib;
				sib->p = del->p;
			}

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

			void	delete_fixup(node* x)
			{
				node* w;
				while (x != root && x->isred == false)
				{
					if (x == x->p->left)
					{
						w = x->p->right;
						if (w->isred == true)
						{
							w->isred = false;
							x->p->isred = true;
							left_rotate(x->p);
							w = x->p->right;
						}
						if (w->left->isred == false && w->right->isred == false)
						{
							w->isred = true;
							x = x->p;
						}
						else
						{
							if (w->right->isred == false)
							{
								w->left->isred = false;
								w->isred = true;
								right_rotate(w);
								w = x->p->right;
							}
							w->isred = x->p->isred;
							x->p->isred = false;
							w->right->isred = false;
							left_rotate(x->p);
							x = root;
						}
					}
					else
					{
						w = x->p->left;
						if (w->isred == true)
						{
							w->isred = false;
							x->p->isred = true;
							right_rotate(x->p);
							w = x->p->left;
						}
						if (w->right->isred == false && w->left->isred == false)
						{
							w->isred = true;
							x = x->p;
						}
						else
						{
							if (w->left->isred == false)
							{
								w->right->isred = false;
								w->isred = true;
								left_rotate(w);
								w = x->p->left;
							}
							w->isred = x->p->isred;
							x->p->isred = false;
							w->left->isred = false;
							right_rotate(x->p);
							x = root;
						}
					}
				}
				x->isred = false;
			}

			void	delete_node(node* del)
			{
				node* x;
				node* y = del;
				bool y_orig_color =  y->isred;
				if (del->left->data == NULL)
				{
					x = del->right;
					// delete del->left;
					transplant(del, del->right);
					del->right = NULL;
				}
				else if (del->right->data == NULL)
				{
					x = del->left;
					// delete del->right;
					transplant(del, del->left);
					del->left = NULL;
				}
				else
				{
					y = del->right;
					while (y->left->data)
						y = y->left;
					y_orig_color = y->isred;
					x = y->right;
					if (y->p == del)
						x->p = y;
					else
					{
						transplant(y, y->right);
						y->right = del->right;
						y->right->p = y;
					}
					transplant(del, y);
					delete y->left;
					y->left = del->left;
					y->left->p = y;
					y->isred = del->isred;
					del->right = NULL;
					del->left = NULL;
				}
			
				if (y_orig_color == false)
					delete_fixup(x);
				delete del;
			}

			size_type erase (const key_type& k)
			{
				current = &root;
				while ((*current)->data != NULL)
				{
					if ((*current)->data && (*current)->data->first == k)
					{
	
						delete_node((*current));
						_size--;
						return (1);
					}
					else if (value_compare(_comp).comp((*current)->data->first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				return (0);
			}

			void erase (iterator position)
			{
				erase(position->first);
			}

			void erase (iterator first, iterator last)
			{
				iterator tmp = first;
				iterator t = first;
				while (&*tmp != &*last)
				{
					tmp++;
					erase(t->first);
					t = tmp;
				}
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
				const_iterator tm(tmp, root);
				const_iterator f(tm);
				return (f);
			}

			const_iterator begin() const
			{
				node* tmp = root;
				while (tmp && tmp->left && tmp->left->data)
					tmp = tmp->left;
				const_iterator tm(tmp, root);
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

			iterator lower_bound( const Key& key )
			{
				node* tmp = root;
				node* pr;
				while (tmp->data != NULL)
				{
					pr = tmp;
					if (tmp->data && tmp->data->first == key)
						return(iterator(tmp, root));
					else if (_comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				iterator t(pr, root);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			const_iterator lower_bound( const Key& key ) const
			{
				node* tmp = root;
				node* pr;
				while (tmp->data != NULL)
				{
					pr = tmp;
					if (tmp->data && tmp->data->first == key)
						return(const_iterator(tmp, root));
					else if (_comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				const_iterator t(pr, root);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			iterator upper_bound( const Key& key )
			{
				node* tmp = root;
				node* pr;
				while (tmp->data != NULL)
				{
					pr = tmp;
					if (tmp->data && tmp->data->first == key)
					{
						iterator t(tmp, root);
						t++;
						return (t);
					}
					else if (value_compare(_comp).comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				iterator t(pr, root);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			const_iterator upper_bound( const Key& key ) const
			{
				node* tmp = root;
				node* pr;
				while (tmp->data != NULL)
				{
					pr = tmp;
					if (tmp->data && tmp->data->first == key)
					{
						const_iterator t(tmp, root);
						t++;
						return (t);
					}
					else if (value_compare(_comp).comp(tmp->data->first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				const_iterator t(pr, root);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			ft::pair<iterator,iterator> equal_range( const Key& key )
			{
				iterator low = lower_bound(key);
				iterator up = upper_bound(key);
				return (ft::pair<iterator, iterator>(low, up));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				const_iterator low = lower_bound(key);
				const_iterator up = upper_bound(key);
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