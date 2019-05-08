queue< STATE_TYPE > q;
q.push( START_STATE );
vis[ START_STATE ] = 1;
while(!q.empty()){
	STATE_TYPE u = q.front();
	q.pop();
	if( u 满足终止条件 )break;
	for( u 的所有后续状态 v ){
		if(vis[v])continue;
		q.push(v);
		vis[v] = 1;
	}
}

