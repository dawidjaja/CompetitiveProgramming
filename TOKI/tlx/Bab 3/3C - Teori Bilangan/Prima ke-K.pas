var
	mskn,prime,lol:array[0..1000000] of longint;
	msk,i,n,x:longint;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(mskn[i]);
		end;
	for i:=1 to 1000000 do 
		begin
		lol[i]:=1;
		end;
	x:=1;
	for i:=2 to 1000000 do
		begin
		if lol[i]=1 then
			begin
			for n:=1 to (1000000 div i) do
				begin
				if (i div n) = i then
					begin
					prime[x]:=i;
					x:=x+1;
					end
				else
					begin
					lol[n*i]:=0;
					end;
				end;
			end;
		end;
	for i:=1 to msk do
		begin
		writeln(prime[mskn[i]]);
		end;
end.