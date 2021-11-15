#ifndef NODE_HPP
#define NODE_HPP

#include <deque>
#include <list>
#include <unordered_map>
#include <stdexcept>

/* This header file provides a node template object that can be used to 
 * find routes on a directed or undirected graph. 
 * The implementation is written in the header because this class is templated. */

template<typename T>
class Node{

	private:
		T value;
		std::list<Node*> children;

	public:
		Node<T>() {}
		
		Node<T>(T _value) : value(_value) { }
		
		void addChild(Node* _node) {
			children.push_back(_node);
		}
		
		std::list<Node*> getChildren(){ return children; }
		
		void setValue(T _value){
			value = _value;
		}
		
		T getValue() {return value;}
		
		/* This function returns an ordered list containing the shortest route
		 * between this node and some other specified node. 
		 * If the requested destination cannot be found, the list returns empty. */
		std::list<Node<T>*> routeTo(Node<T>* destination){
		
			Node<T>* root = this; //root node is the beginning of our search
			std::deque<Node<T>*> queue;
			std::unordered_map<Node<T>*, bool> visited; //whether node has been visited
			std::unordered_map<Node<T>*, int> d; //distance from root (path cost)
			std::unordered_map<Node<T>*, Node<T>*> p; //parent of each node
			
			d[root] = 0; //distance from root to root is obviously 0
			p[root] = nullptr; //root has no parent
			
			queue.push_back(root);
			visited[root] = true;
			
			//BFS algorithm
			while(true){
			
				if(queue.empty()){
					throw std::domain_error("No route between given nodes");
				}
			
				Node<T>* next = queue.front();
				queue.pop_front();
				
				//stop early when we find the destination
				if(next == destination){ 
					break; 
				}
				
				auto children = next->getChildren();
				for(Node<T>* child : children){
					
					//If this node has not yet been visited
					if(visited[child] == false){ 
						
						//Mark this node as visited
						visited[child] = true;
					
						//The child is 1 step further from the parent
						d[child] = d[next] + 1; 
						
						//Add parent node to the map
						p[child] = next;
						
						queue.push_back(child);
						
					}
				}
			}
			
			//If distance is 0 (ie. destination and root are the same,) return empty route
			//Also return empty route if destination is invalid 
			if(d[destination] == 0){
				return std::list<Node<T>*>();
			}
			
			/* Starting at the destination, use the parent map to find each 
			 * consecutive node back to the root in reverse. This is the route. */
			std::list<Node<T>*> route;
			Node<T>* di = destination;
			while(p[di] != nullptr){
				route.push_front(di);
				di = p[di];
			}
			route.push_front(di);
			return route;
	}
};

#endif
