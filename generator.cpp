#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

long long getLL(const vector<string>& a,const string& key,long long def){
    string p1=key+"=",p2="--"+key+"=";
    for(auto &s:a){
        if(s.rfind(p1,0)==0)return stoll(s.substr(p1.size()));
        if(s.rfind(p2,0)==0)return stoll(s.substr(p2.size()));
    }
    return def;
}
int main(int argc,char* argv[]){
    registerGen(argc,argv,1);
    vector<string> args;
    for(int i=1;i<argc;i++)args.push_back(argv[i]);
    int T=(int)getLL(args,"t",10);
    int maxN=(int)getLL(args,"maxN",100000);
    int sumN=(int)getLL(args,"sumN",200000);
    long long maxProfit=getLL(args,"maxProfit",1000000000LL);
    long long maxW=getLL(args,"maxW",1000000000LL);
    int mode=(int)getLL(args,"mode",0);
    if(sumN<T)sumN=T;
    if(maxProfit<1)maxProfit=1;
    if(maxW<0)maxW=0;
    cout<<T<<"\n";
    vector<int> n(T);
    int remaining=sumN;
    for(int i=0;i<T;i++){
        int left=T-i-1;
        int upper=min(maxN,remaining-left);
        n[i]=(i==T-1?upper:rnd.next(1,upper));
        remaining-=n[i];
    }
    shuffle(n.begin(),n.end());
    for(int tc=0;tc<T;tc++){
        int N=n[tc];
        if(mode==2 && tc%12==0)N=1;
        vector<vector<long long>> p(3,vector<long long>(N));
        vector<vector<long long>> w(3,vector<long long>(3,0));
        for(int s=0;s<3;s++){
            for(int i=0;i<N;i++){
                p[s][i]=rnd.next(1LL,maxProfit);
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j)w[i][j]=0;
                else w[i][j]=(maxW==0?0:rnd.next(1LL,maxW));
            }
        }
        if(mode==2){
            int type=tc%12;
            if(type==0){
                long long v=rnd.next(1LL,maxProfit);
                p[0][0]=p[1][0]=p[2][0]=v;
            }
            else if(type==3){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)w[i][j]=0;
                }
            }
            else if(type==4){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)w[i][j]=(i==j?0:maxW);
                }
            }
            else if(type==5){
                for(int i=0;i<3;i++)for(int j=0;j<3;j++)w[i][j]=0;
                if(maxW>0){
                    w[0][1]=1;w[1][0]=maxW;
                    w[1][2]=1;w[2][1]=maxW;
                    w[2][0]=1;w[0][2]=maxW;
                }
            }
            else if(type==6){
                long long v=rnd.next(1LL,maxProfit);
                for(int s=0;s<3;s++){
                    for(int i=0;i<N;i++)p[s][i]=v;
                }
            }
            else if(type==7){
                for(int i=0;i<N;i++){
                    p[0][i]=maxProfit;
                    p[1][i]=1;
                    p[2][i]=1;
                }
            }
            else if(type==8){
                for(int i=0;i<N;i++){
                    int best=i%3;
                    for(int s=0;s<3;s++)p[s][i]=rnd.next(1LL,max(1LL,maxProfit/3));
                    p[best][i]=rnd.next(max(1LL,(2LL*maxProfit)/3),maxProfit);
                }
            }
            else if(type==9){
                long long X=(maxProfit>=2?rnd.next(2LL,maxProfit):1LL);
                for(int i=0;i<N;i++){
                    int best=rnd.next(0,2);
                    for(int s=0;s<3;s++){
                        if(s==best)p[s][i]=X;
                        else p[s][i]=(X==1?1:rnd.next(1LL,X-1));
                    }
                }
            }
            else if(type==10){
                for(int s=0;s<3;s++)for(int i=0;i<N;i++)p[s][i]=maxProfit;
                for(int i=0;i<3;i++)for(int j=0;j<3;j++)w[i][j]=(i==j?0:maxW);
            }
        }
        long long mx=0;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)mx=max(mx,w[i][j]);
        long long maxUsefulK=1LL*max(0,N-1)*mx;
        long long k=0;
        if(mode==1){
            k=0;
        }
        else if(mode==2){
            int type=tc%12;
            if(type==1)k=0;
            else if(type==2)k=maxUsefulK;
            else if(type==10)k=1000000000000000000LL;
            else k=(maxUsefulK==0?0:rnd.next(0LL,maxUsefulK));
        }
        else{
            k=((maxUsefulK==0)?0:rnd.next(0LL,maxUsefulK));
        }
        cout<<N<<" "<<k<<"\n";
        for(int s=0;s<3;s++){
            for(int i=0;i<N;i++){
                cout<<p[s][i]<<" \n"[i==N-1];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<w[i][j]<<" \n"[j==2];
            }
        }
    }
    return 0;
}