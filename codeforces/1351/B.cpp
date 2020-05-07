    #include <iostream>
     
    using namespace std;
    long long t,a,b,a2,b2;
    int main()
    {
        cin>>t;
        while(t)
        {
            t--;
            cin>>a>>b>>a2>>b2;
            if(a>b)
                swap(a,b);
            if(a2>b2)
                swap(a2, b2);
                
            if(b==b2 && a+a2==b)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }