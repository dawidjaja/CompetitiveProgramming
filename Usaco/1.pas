var
	list:array[0..200000,0..2] of longint;
	msk,i,n,jttl,jskip,slsh,seto,ttl:longint;
	a:text;
begin
	assign(A,'marathon.in');
	reset(A);
	readln(A,msk);
	for i:=1 to msk do
		begin
		for n:=1 to 2 do
			begin
			read(A,list[i,n]);
			end;
		end;
	close(A);
	seto:=0;
	for i:=2 to msk do
		begin
		jttl:=(abs(list[i,1]-list[(i-1),1])+abs(list[i,2]-list[(i-1),2])+abs(list[i,1]-list[(i+1),1])+abs(list[i,2]-list[(i+1),2]));
		jskip:=(abs(list[i-1,1]-list[i+1,1])+abs(list[i-1,2]+list[i+1,2]));
		slsh:=jttl-jskip;
		if slsh>seto then
			begin
			seto:=slsh;
			end;
		end;
	ttl:=0;
	for i:=2 to msk do
		begin
		ttl:=ttl+(abs(list[i,1]-list[i-1,1])+abs(list[i,2]-list[i-1,2]));
		end;
	ttl:=ttl-seto;
	assign(A,'marathon.out');
	rewrite(A);
	writeln(A,ttl);
	close(A);
end.