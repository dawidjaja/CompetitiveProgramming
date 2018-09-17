var
	list:array[1..10000] of real;
	a,x:longint;
	n,m,s:real;
begin
	readln(a);
	s:=0;
	for x:=1 to a do
	begin
		readln(list[x]);
	end;
	n:=list[1];
	m:=list[1];
	for x:=1 to a do
	begin
		if list[x]<n then
		begin
			n:=list[x];
		end;
	end;
	for x:=1 to a do
	begin
		if list[x]>m then
		begin
			m:=list[x];
		end;
	end;
	for x:=1 to a do
	begin
		s:=s+list[x];
	end;
	s:=s/a;
	write(n:0:2, ' ', m:0:2, ' ', s:0:2);
	writeln;
end.