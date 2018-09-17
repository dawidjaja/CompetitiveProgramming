var
	list:array[0..100000] of longint;
	msk,i,tgh,x,ttl,n:longint;
begin
	readln(msk);
	if msk<2 then
		begin
		writeln('*');
		end;
	if msk>=2 then
		begin
		x:=2;
		while x<> msk+1 do
			begin
			list[1]:=(1);
			tgh:=1;
			ttl:=1;
			for i:=2 to x do
				begin
				tgh:=tgh*2;
				ttl:=(((ttl+1)*2)-1);
				end;
			list[tgh]:=x;
			for i:=1 to tgh-1 do
				begin
				list[ttl-i+1]:=list[i];
				end;
				x:=x+1;
			end;
		for i:=1 to ttl do
			begin
			for n:=1 to list[i] do
				begin
				write('*');
				end;
			writeln;
			end;
		end;
end.