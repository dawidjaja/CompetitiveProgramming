var
	n,m,i:longint;
	jmlh,temp:int64;
	kado:array[0..1000000] of longint;
begin
readln(n,m);
jmlh:=0;
for i:=1 to n do
	begin
	read(kado[i]);
	if i<=m then
		begin
		jmlh:=jmlh+kado[i];
		temp:=jmlh;
		end;
	if i>m then
		begin
		jmlh:=jmlh+kado[i]-kado[i-m];
		if jmlh>temp then
			begin
			temp:=jmlh;
			end;
		end;
	end;
writeln(temp);
end.