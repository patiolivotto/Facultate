#ifndef __HASHTABLE__H
#define __HASHTABLE__H
 
template<typename Tkey, typename Tvalue> struct elem_info {
        Tkey key;
        Tvalue value;
};
 
template<typename Tkey, typename Tvalue> class Hashtable {
        private:
                LinkedList<struct elem_info<Tkey, Tvalue> > *H;
                int HMAX;
                int (*hash) (Tkey);
        public:
                Hashtable(int hmax,  int (*h)(Tkey)){
                	HMAX = hmax;
                	hash = h;
                	H = new LinkedList<struct elem_info<Tkey, Tvalue> > [HMAX];
                };
                ~Hashtable(){
                 	/*for (int i = 0; i < HMAX; i++) {
                 		while (!H[i].isEmpty())
                	        H[i].removeFirst();
                	}
                	delete H;
                	*/
                };
 			//functia put key
                void put(Tkey key, Tvalue value){
                	struct Node<struct elem_info<Tkey, Tvalue> > *p;
                	struct elem_info<Tkey, Tvalue> info;
                	int hkey = hash(key);
                	p = H[hkey].pFirst;
                	while (p != NULL) {
           			 //std::cout<<"intra";
                		if (strcmp(p->value.key , key)==0)
                			break;
                		//	std::cout<<"intra";
                		p = p->next;
                	}
                	if (p != NULL)
                		p->value.value = value;
                	else {
                		info.key = key;
                		info.value = value;
                		H[hkey].addLast(info);
                	}
                };
                //functia get key
                Tvalue get(Tkey key){
                	struct Node<struct elem_info<Tkey, Tvalue> > *p;
                	struct Node<struct elem_info<Tkey, Tvalue> > *r;
                	int hkey = hash(key);
                	p = H[hkey].pFirst;
                	while (p != NULL) {
                		if (strcmp(p->value.key , key)==0) break;
                		p = p->next;
                	}
                	r =  H[hkey].pFirst;
                	if (p != NULL) {
                		while (r != NULL){
                		std::cout<<p->value.value<<" <x< \n ";
                		r=r->next;
                		}
                   		return p->value.value;
                   	}
                	else {
                		printf( "The key does not exist in the ht\n");
                		
                		return 0;
                	}
                };
                //functia  has key
                bool hasKey(Tkey key){
					struct Node<struct elem_info<Tkey, Tvalue> > *p;
					int hkey = hash(key);
					p = H[hkey].pFirst;
					while (p != NULL) {
						if (strcmp(p->value.key , key)==0)
							break;
						p = p->next;
					}
            		if (p != NULL)
            			return 1;
            		else
            			return 0;
            	}
};

 
#endif // __HASHTABLE__H
