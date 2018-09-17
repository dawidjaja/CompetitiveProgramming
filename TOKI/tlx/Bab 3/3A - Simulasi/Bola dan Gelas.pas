var
	list,temp:array[1..100000] of longint;
	a,b,n,m,re,jmlh,i:longint;
begin
	readln(n,m);
	for i:=1 to 100000 do
		begin
		list[i]:=i;
		end;
	for i:=1 to m do
		begin
		readln(a,b);
		re:=list[a];
		list[a]:=list[b];
		list[b]:=re;
		end;
	readln(jmlh);
	for i:=1 to jmlh do
		begin
		readln(temp[i]);
		end;
	for i:=1 to jmlh do
		begin
		writeln(list[temp[i]]);
		end;
end.