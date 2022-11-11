#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template < class T>
	struct	node_d
	{

		typedef T		value_type;
		value_type		data;
		bool			isred;
		// typedef typename std::allocator<value_type>::template rebind<node_d>::other	node_alloc;

		node_d*		left;
		node_d*		right;
		node_d*		p;
		// node_alloc	n_alloc;

		node_d(value_type val, node_d* parent) : data(val), p(parent)
		{
			left = NULL;
			right = NULL;
			isred = true;
			// n_alloc = all;
		}

		node_d(node_d* parent) : data()
		{
			left = NULL;
			right = NULL;
			isred = false;
			p = parent;
			// n_alloc = all;
		}

		// node_d(const node_d& x)
		// {
		// 	data = x.data;
		// 	left = x.left;
		// 	right = x.right;
		// 	isred = x.isred;
		// 	p = x.p;
		// 	n_alloc = x.n_alloc;
		// }

		~node_d()
		{
			// if (left)
			// {
			// 	n_alloc.destroy(left);
			// 	n_alloc.deallocate(left, 1);
			// }
			// if (right)
			// {
			// 	n_alloc.destroy(right);
			// 	n_alloc.deallocate(right, 1);
			// }
		}
	};

	template < 
		class T,
		class Compare,
		class Allocator
	> class tree
	{
		public:

			typedef	T												value_type;
			typedef Compare											key_compare;
			typedef ft::node_d<value_type>							node;
			typedef ft::tree_iterator<node, value_type>				iterator;
			typedef ft::tree_const_iterator<node, value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename value_type::first_type					key_type;
			typedef typename value_type::second_type				mapped_type;

		private:
			typedef typename Allocator::template rebind<node>::other	node_alloc;
			typedef typename node_alloc::pointer						pointer;

			node_alloc	n_alloc;
			pointer		root;
			pointer*	current;
			std::size_t	_size;
			key_compare	_comp;

		public:
			~tree()
			{
				clear_node(root);
			}
			
			tree()
			{
				root = NULL;
				current = NULL;
				_size = 0;
				n_alloc = node_alloc();
				_comp = key_compare();
			}

			void  swap(tree& x)
			{
				std::swap(root, x.root);
				std::swap(current, x.current);
				std::swap(_size, x._size);
				std::swap(n_alloc, x.n_alloc);
				std::swap(_comp, x._comp);
			}

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
				if (y->left != NULL)
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
				if (y->right != NULL)
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
				if (del->left->left == NULL)
				{
					x = del->right;
					transplant(del, del->right);
					del->right = NULL;
				}
				else if (del->right->left == NULL)
				{
					x = del->left;
					transplant(del, del->left);
					del->left = NULL;
				}
				else
				{
					y = del->right;
					while (y->left->left)
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
					clear_node(y->left);
					y->left = del->left;
					y->left->p = y;
					y->isred = del->isred;
					del->right = NULL;
					del->left = NULL;
				}
			
				if (y_orig_color == false)
					delete_fixup(x);
				clear_node(del);
			}

			std::size_t erase (const key_type& k)
			{
				current = &root;
				while ((*current)->left != NULL)
				{
					if ((*current)->left && (*current)->data.first == k)
					{
	
						delete_node((*current));
						_size--;
						return (1);
					}
					else if (_comp((*current)->data.first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				return (0);
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
								left_rotate(tmp);
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
								right_rotate(tmp);
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

			node* new_node(const value_type& val, node* parent)
			{
				n_alloc = node_alloc();
				node* tmp = n_alloc.allocate(1);
				n_alloc.construct(tmp, node(val, parent));

				return (&*tmp);
			}

			node* new_node_p(node* parent)
			{
				n_alloc = node_alloc();
				node* tmp = n_alloc.allocate(1);
				n_alloc.construct(tmp, node(parent));

				return (&*tmp);
			}
			
			void clear_node(node* n)
			{
				if (n)
				{
					clear_node(n->left);
					clear_node(n->right);
					n_alloc.destroy(n);
					n_alloc.deallocate(n, 1);
				}
			}

			void clear()
			{
				clear_node(root);
				_size = 0;
				root = NULL;
			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (root == NULL)
				{
					root = new_node(val, NULL);
					root->left = new_node_p(root);
					root->right = new_node_p(root);
					current = &root;
					root->isred = false;
					_size++;
					return (ft::pair<iterator, bool>(iterator(&*(*current)), true));
				}
				current = &root;
				node *p;
				while ((*current)->left != NULL)
				{
					p = *current;
					if ((*current)->left && (*current)->data.first == val.first)
						return(ft::pair<iterator, bool>((iterator(&*(*current))), false));
					else if (_comp((*current)->data.first, val.first))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				n_alloc.destroy(*current);
				n_alloc.deallocate(*current, 1);
				*current = new_node(val, p);
				(*current)->left = new_node_p(*current);
				(*current)->right = new_node_p(*current);
				(*current)->isred = true;
				node* tmp;
				tmp = insert_fixup((*current));
				current = &tmp;
				_size++;
				return (ft::pair<iterator, bool>((iterator(&*(*current))), true));
			}

			iterator begin()
			{
				current = &root;
				while ((*current) && (*current)->left->left)
					current = &(*current)->left;
				iterator tm(&*(*current));
				return (tm);
			}

			const_iterator begin() const
			{
				node* tmp = root;
				while (tmp && tmp->left->left)
					tmp = tmp->left;
				const_iterator tm(&*tmp);
				return (tm);
			}

			iterator end()
			{
				current = &root;
				while ((*current) && (*current)->right)
					current = &(*current)->right;
				iterator tm(&*(*current));
				return (tm);
			}

			const_iterator end() const
			{
				node* tmp = root;
				while (tmp && tmp->right)
					tmp = tmp->right;
				const_iterator tm(&*tmp);
				return (tm);
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

			std::size_t size() const
			{
				return _size;
			}

			bool empty() const
			{
				return !_size;
			}

			mapped_type& at (const key_type& k)
			{
				current = &root;
				while ((*current)->left != NULL)
				{
					if ((*current)->left && (*current)->data.first == k)
						return((*current)->data.second);
					else if (_comp((*current)->data.first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				throw std::out_of_range("Dont have this key");
			}

			const mapped_type& at (const key_type& k) const
			{
				current = &root;
				while ((*current)->left != NULL)
				{
					if ((*current)->left && (*current)->data.first == k)
						return((*current)->data.second);
					else if (_comp((*current)->data.first, k))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				throw std::out_of_range("Dont have this key");
			}
			
			std::size_t max_size() const
			{
				return (n_alloc.max_size());
			}

			std::size_t count( const key_type& key ) const
			{
				node*	tmp = root;
				while (tmp->left != NULL)
				{
					if (tmp->left && tmp->data.first == key)
						return(1);
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return 0;
			}

			iterator find( const key_type& key )
			{
				node* tmp = root;
				while (tmp->left != NULL)
				{
					if (tmp->left && tmp->data.first == key)
						return(iterator(tmp));
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return (end());
			}

			const_iterator find( const key_type& key ) const
			{
				node* tmp = root;
				while (tmp->left != NULL)
				{
					if (tmp->left && tmp->data.first == key)
						return(const_iterator(tmp));
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				return (end());
			}

			iterator lower_bound( const key_type& key )
			{
				node* tmp = root;
				node* pr;
				while (tmp->left != NULL)
				{
					pr = tmp;
					if (tmp->left && tmp->data.first == key)
						return(iterator(tmp));
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				iterator t(pr);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			const_iterator lower_bound( const key_type& key ) const
			{
				node* tmp = root;
				node* pr;
				while (tmp->left != NULL)
				{
					pr = tmp;
					if (tmp->left && tmp->data.first == key)
						return(const_iterator(tmp));
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				const_iterator t(pr);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			iterator upper_bound( const key_type& key )
			{
				node* tmp = root;
				node* pr;
				while (tmp->left != NULL)
				{
					pr = tmp;
					if (tmp->left && tmp->data.first == key)
					{
						iterator t(tmp);
						t++;
						return (t);
					}
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				iterator t(pr);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			const_iterator upper_bound( const key_type& key ) const
			{
				node* tmp = root;
				node* pr;
				while (tmp->left != NULL)
				{
					pr = tmp;
					if (tmp->left && tmp->data.first == key)
					{
						const_iterator t(tmp);
						t++;
						return (t);
					}
					else if (_comp(tmp->data.first, key))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				const_iterator t(pr);
				if (&*t == &*(end()))
					return (end());
				if (tmp == tmp->p->left)
					return (t);
				t++;
				return (t);
			}

			ft::pair<iterator,iterator> equal_range( const key_type& key )
			{
				iterator low = lower_bound(key);
				iterator up = upper_bound(key);
				return (ft::pair<iterator, iterator>(low, up));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
			{
				const_iterator low = lower_bound(key);
				const_iterator up = upper_bound(key);
				return (ft::pair<const_iterator, const_iterator>(low, up));
			}
			
	};
}



#endif