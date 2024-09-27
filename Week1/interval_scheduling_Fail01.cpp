//peerapat saengphoem 6530300376
#include <iostream>
using namespace std;
struct record{
	int link_S;
	int link_F;
	struct record *next;
};

struct record *insert(struct record *head,int s,int f){
	if(head == NULL){
		head = new struct record;
		head->link_S = s;
		head->link_F = f;
		head->next = NULL;
	}else{
		struct record *p=head,*node;
		node = new struct record;
		node ->link_S = s;
		node ->link_F = f;
		
		if(f < p->link_F){
			node->next = p;
			p = node;
			return p;
		}else{
			while(p->next != NULL){
				if(f<p->next->link_F){
					node->next = p->next;
					p->next = node;
					break;
				}else{
					p=p->next;
				}
			}if(p->next == NULL){
				node->next = NULL;
				p->next=node;
			}
		}
	}
	return head;
}

int main(){
	int in1,s,f;
	int count=0;
	int time = -1;
	
	struct record *head = NULL;
	cin >> in1;
	
	for(int i=0;i<in1 ;i++){
		cin >> s;
		cin >> f;
		head=insert(head,s,f);
	}
	
	struct record *p = head;
	while(p){
		if(p->link_S >= time){
			time = p->link_F;
			count++;
		}
		p=p->next;
	}
	cout << count;
}
