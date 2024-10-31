//huffman coding cpp
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
#define NUM 100005
#define SIZE 26

struct Info{
	Info(){

		node_index = 0;
		value = 0;
	}
	Info(int arg_node_index,ll arg_value){
		node_index = arg_node_index;
		value = arg_value;
	}
	bool operator<(const struct Info &arg) const{
		return value > arg.value; 
	}
	int node_index;
	ll value;
};

struct Node{

	int ch,left_child,right_child;
	ll value,depth;
};

char buf[NUM];
ll table[SIZE];
int node_index;
Node nodes[2*SIZE];

void calcDepth(int node_id,ll DEPTH){

	nodes[node_id].depth = DEPTH;

	if(nodes[node_id].left_child == -1)return;

	calcDepth(nodes[node_id].left_child,DEPTH+1);
	calcDepth(nodes[node_id].right_child,DEPTH+1);
}

int main(){

	for(int i = 0; i < SIZE; i++){

		table[i] = 0;
	}

	scanf("%s",buf);

	
	for(int i = 0; buf[i] != '\0'; i++){

		table[buf[i]-'a']++;
	}

	node_index = 0;

	priority_queue<Info> Q;

	for(int i = 0; i < SIZE; i++){
		if(table[i] == 0)continue;

		nodes[node_index].ch = i;
		nodes[node_index].left_child = -1;
		nodes[node_index].right_child = -1;
		nodes[node_index].value = table[i];

		Q.push(Info(node_index,table[i]));
		node_index++;
	}

	if(Q.size() == 1){

		printf("%lld\n",Q.top().value);
		return 0;
	}

	Info left,right;

	while(Q.size() > 1){

		right = Q.top();
		Q.pop();

		left = Q.top();
		Q.pop();

		nodes[node_index].ch = -1; 
		nodes[node_index].value = left.value+right.value;
		nodes[node_index].left_child = left.node_index;
		nodes[node_index].right_child = right.node_index;

		Q.push(Info(node_index,nodes[node_index].value));

		node_index++;
	}

	calcDepth(node_index-1,0);

	ll ans = 0;

	for(int i = 0; i < node_index; i++){
		if(nodes[i].ch == -1)continue;

		ans += nodes[i].depth*table[nodes[i].ch]; 
	}

	printf("%lld\n",ans);

	return 0;
}
