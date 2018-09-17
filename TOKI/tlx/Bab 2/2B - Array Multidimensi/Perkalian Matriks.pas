var
	list,lol:array[0..100,0..100] of integer;
	a,b,i,j,k,l,m,n,o,x,y,z:longint;
begin
	readln(x,y);
	for i:=1 to x do
		begin
			for j:=1 to y do
				begin
				read(list[i,j]);
				end;
		end;
	readln(a,b);
	for k:=1 to a do
		begin
			for l:=1 to b do
				begin
				read(lol[k,l]);
				end;
		end;
	for m:=1 to x do
		begin
		for n:=1 to b do
			begin
			if n=b then
				begin
					for o:=1 to y do
					begin
					z:=list[m,o]*lol[o,n]+z
					end;
				write(z);
				end
			else
				begin
					for o:=1 to y do
					begin
					z:=list[m,o]*lol[o,n]+z
					end;
				write(z);
				write(' ');
				end;
			z:=0;
			end;
			writeln();
		end;
end.