template <typename T>
T read(){
    T res=0;char c;
    bool minus=false;
    while(1){
        c=getchar_unlocked();
        if(c==' '||c=='\n') continue;
        if(c=='-')minus=true;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&& c<='9') res=10*res+c-'0';
        else break;
    }
    return (minus)? -res : res;
}
