var
	list:array[1..1000]of longint;
	a,b,c,d,i,j,k:longint;
begin
	c:=0;
	for i:=1 to 1000 do
		begin
		list[i]:=0;
		end;
		readln(a);
	for j:=1 to a do
		begin
		readln(b);
		list[b]:=list[b]+1;
		end;
	for k:=1 to 1000 do
		begin
		if list[k]>=c then
			begin
			c:=list[k];
			d:=k;
			end;
		end;
	writeln(d);
end.