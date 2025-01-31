#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int _size[1000];
int _rank[1000];

void make_set(int v){
    parent[v] = v;
    _size[v] = 1;
    _rank[v] = 0;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return find_set(parent[v]);
}

/*
using loop

int find_set(int v){
    int a = v;
    while(a != parent[a]){
        a = parent[a];
    }
    return a;
}
*/

void union_naive(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    parent[a] = b;
}

void union_by_size(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(_size[a] > _size[b]){
        parent[b] = a;
        _size[a] += _size[b];
    }
    else{
        parent[a] = b;
        _size[b] += _size[a];
    }
}

void union_by_rank(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(_rank[a] > _rank[b]){
        parent[b] = a;
    }
    else if(_rank[b] > _rank[a]){
        parent[a] = b;
    }
    else{
        if(_size[a] > _size[b]){
            parent[b] = a;
            _rank[a]++;
        }
        else{
            parent[a] = b;
            _rank[b]++;
        }
    }
}

int main(){

    for(int i=0;i<1000;i++){
        parent[i] = -1;
    }
    for(int i=1;i<=10;i++){
        make_set(i);
    }
}
