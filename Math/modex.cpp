typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

template <typename T>
T modmul(T a,T b, T MOD) {
	T q=(T)(((LD)a*(LD)b)/(LD)MOD);
	T r=a*b-q*MOD;
	if (r>MOD) r %= MOD;
	if (r<0) r += MOD;
	return r;
}

template <typename T>
T modex(T x,T y,T mod){
    T res=1;x%=mod;
    while(y>0){
        if(y&1)
            //res=(res*x)%mod;
            res=(modmul<T>(x,p,mod));
        y>>=1;
        //x=(x*x)%mod;
        x = modmul<T>(x,x,mod);
    }
    return res;
}