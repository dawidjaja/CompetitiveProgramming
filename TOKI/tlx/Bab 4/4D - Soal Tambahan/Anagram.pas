var
    cek:array[0..10000] of longint;
    list,ts,akhir:array[0..10000] of string;
    msk,n,i,j,k,hsl:longint;
    kata,ans:string;
procedure swapk(var a,b:char);
var
    c:char;
begin
    c:=a;
    a:=b;
    b:=c;
end;
  
procedure sortk(left,right:longint);
var i,a,e:longint;piv:char;
begin
    i:=left;
    a:=right;
    e:=(i+a) div 2;
    piv:=kata[e];
    while (i<=a) do
    begin
        while kata[i]<piv do i:=i+1;
        while kata[a]>piv do a:=a-1;
        if (i<=a) then
        begin
            swapk(kata[i],kata[a]);
            i:=i+1;
            a:=a-1;
        end;
    end;
    if left < a then sortk(left,a);
    if i < right then sortk(i,right);
end;
procedure swapb(var a,b:longint);
var
    c:string;
begin
    c:=list[a];
    list[a]:=list[b];
    list[b]:=c;
    c:=ts[a];
    ts[a]:=ts[b];
    ts[b]:=c;
end;
  
procedure sortb(left,right:longint);
var i,a,e:longint;piv:string;
begin
    i:=left;
    a:=right;
    e:=(i+a) div 2;
    piv:=ts[e];
    while (i<=a) do
    begin
        while ts[i]<piv do i:=i+1;
        while ts[a]>piv do a:=a-1;
        if (i<=a) then
        begin
            swapb(i,a);
            i:=i+1;
            a:=a-1;
        end;
    end;
    if left < a then sortb(left,a);
    if i < right then sortb(i,right);
end;
procedure swapa(var a,b:string);
var
    c:string;
begin
    c:=a;
    a:=b;
    b:=c;
end;
 
procedure sorta(left,right:longint);
var i,a,e:longint;piv:string;
begin
    i:=left;
    a:=right;
    e:=(i+a) div 2;
    piv:=akhir[e];
    while (i<=a) do
    begin
        while akhir[i]<piv do i:=i+1;
        while akhir[a]>piv do a:=a-1;
        if (i<=a) then
        begin
            swapa(akhir[i],akhir[a]);
            i:=i+1;
            a:=a-1;
        end;
    end;
    if left < a then sorta(left,a);
    if i < right then sorta(i,right);
end;
begin
    readln(msk);
    for i:=1 to msk do
        begin
        cek[i]:=0;
        readln(list[i]);
        kata:=list[i];
        sortk(1,length(kata));
        ts[i]:=kata;
        end;
    sortb(1,msk);
    hsl:=0;
    n:=1;
    k:=1;
    kata:='';
    ans:='~';
    for i:=1 to msk do
        begin
        if ts[i+1]<>ts[i] then
            begin
            if n>hsl then
                begin
                ans:='~';
                hsl:=n;
                end;
            for j:=k to i do
                begin
                cek[j]:=n;
                if n>=hsl then
                    begin
                    if list[j]<ans then
                        begin
                        ans:=list[j];
                        kata:=ts[j];
                        end;
                    end;
                end;
            k:=i+1;
            n:=1;
            end
        else
            begin
            n:=n+1;
            end;
        end;
    if hsl=1 then
        begin
        writeln('TIDAK ADA');
        end
    else
        begin
        writeln(hsl);
        n:=1;
        for i:=1 to msk do
            begin
            if (cek[i]=hsl) and (ts[i]=kata) then
                begin
                akhir[n]:=list[i];
                n:=n+1;
                end;
            end;
        sorta(1,n-1);
        for i:=1 to n-1 do
            begin
            writeln(akhir[i]);
            end;
        end;
end.