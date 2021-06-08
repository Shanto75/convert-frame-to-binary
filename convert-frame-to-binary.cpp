#include<bits/stdc++.h>
using namespace std;

string convert(string p)
{
    string a,data;
    int num = stod(p);  //convert string 123 = int 123
    while(num>0)
    {
        int x = num%2;
        num = num/2;
        stringstream st;
        st<<x;
        st>>a;
        data.append(a);
    }
    reverse(data.begin(),data.end());

    return data;
}

string hexaTobinary(string s)
{
    string data;
    switch(s[0])
    {
    case 'A':
    case 'a':
        data = "1010";
        break;
    case 'B':
    case 'b':
        data =  "1011";
        break;
    case 'C':
    case 'c':
        data =  "1100";
        break;
    case 'D':
    case 'd':
        data =  "1101";
        break;
    case 'E':
    case 'e':
        data =  "1110";
        break;
    case 'F':
    case 'f':
        data =  "1111";
        break;
    }
    return data;
}

int main()
{
    string message, port1, port2, ip1, ip2, mac1, mac2, tail,segment,packet, frame, binaryString ;
    int c=0;


    cout<<"message: ";
    cin>>message;
    cout<<"port1: ";
    cin>>port1;
    cout<<"port2: ";
    cin>>port2;
    cout<<"ip1: ";
    cin>>ip1;
    cout<<"ip2: ";
    cin>>ip2;
    cout<<"mac1: ";
    cin>>mac1;
    cout<<"mac2: ";
    cin>>mac2;
    cout<<"tail: ";
    cin>>tail;

    segment.append(port1);
    segment.append(port2);
    segment.append(message);
    packet.append(ip1);
    packet.append(ip2);
    packet.append(segment);
    frame.append(mac1);
    frame.append(mac2);
    frame.append(packet);
    frame.append(tail);

    ///mac to binary
    while(c < mac1.length()+mac2.length())
    {
        if(frame[c]>='0' && frame[c]<='9')
        {
            string s,r;
            r=frame[c];
            s= convert(r);
            binaryString.append(s);
        }
        if((frame[c]>='A'&&frame[c]<='F') || (frame[c]>='a'&&frame[c]<='f') )
        {
            string s,r;
            r = frame[c];
            s = hexaTobinary(r);
            binaryString.append(s);
        }
        c++;
    }

    string s,r;
    int last = ip1.length()+mac1.length()+mac2.length();

    ///ip1 to binary
    while(c<last)
    {
        if(frame[c]>='0'&&frame[c]<='9')
        {
            r = frame[c];
            s.append(r);

        }
        else if(frame[c]=='.')
        {
            r = convert(s);
            binaryString.append(r);
            r.clear();
            s.clear();
        }
        c++;
    }
    r = convert(s);
    binaryString.append(r);

    last = ip1.length()+ip2.length()+mac1.length()+mac2.length();
    r.clear();
    s.clear();
    ///ip2 to binary
    while(c<last)
    {
        if(frame[c]>='0'&&frame[c]<='9')
        {
            r = frame[c];
            s.append(r);

        }
        else if(frame[c]=='.')
        {
            r = convert(s);
            binaryString.append(r);
            r.clear();
            s.clear();
        }
        c++;
    }
    r = convert(s);
    binaryString.append(r);

    r.clear();
    s.clear();

    last= last+port1.length();
    ///port to binary
    while(c<last)
    {
        r = frame[c];
        s.append(r);
        c++;
    }
    r = convert(s);
    binaryString.append(r);

    r.clear();
    s.clear();

    last= last+port2.length();
    while(c<last)
    {
        r = frame[c];
        s.append(r);
        c++;
    }
    r = convert(s);
    binaryString.append(r);

    ///message and tail convert to binary
    last=last+message.length()+tail.length();
    r.clear();
    s.clear();
    while(c<last)
    {
        int x = int(frame[c]);
    stringstream st;
        st<<x;
        st>>r;
    s=convert(r);
    binaryString.append(s);
    c++;
    }


    cout<<endl<<"Frame after converted to binary : "<<binaryString;

}

