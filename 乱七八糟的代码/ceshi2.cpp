void InsertNode(LinkNode<T>*head,LinkNode<T>*ahead){
	LinkNode<T>*tmp=ahead->Link;
	ahead->Link=tmp->Link;
	tmp->Link=head->Link;
	head->Link=tmp;
}

void DeleteNode(LinkNode<T>*head){
	LinkNode<T>*tmp=head->Link;
	head->Link=tmp->Link;
	delete tmp;
}

List combine(const List ha,const List hb){
	List ans;
	LinkNode<T>*ahead=ha.getHead();
	LinkNode<T>*bhead=hb.getHead();
	LinkNode<T>*head=ans.getHead();
	while(ahead->Link!=NULL){
		if(bhead->Link!=NULL){
			if(ahead->data>bhead->data){
				InsertNode(head,bhead);
			}
			else InsertNode(head,ahead);
		}
		else InsertNode(head,ahead);
	}
	while(bhead->Link!=NULL){
		InsertNode(head,bhead);
	}
	return ans;
}

void Reverse(const List a){
	LinkNode<T>*head=a.getHead();
	if(head->Link==NULL)return;
	LinkNode<T>*tail=head;
	while(tail->Link!=NULL)tail=tail->Link;
	LinkNode<T>*tmp=tail;
	while(head->Link!=tail){
		InsertNode(tmp,head);
		tmp=tmp->Link;
		DeleteNode(head);
	}
}
