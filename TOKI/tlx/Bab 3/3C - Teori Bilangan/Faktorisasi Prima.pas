var
	msk,test,x,i,n:longint;
begin
	readln(msk);
	test:=msk;
	x:=0;
	if msk = 1 then
		begin
		writeln(1);
		end
	else
		begin
		for i:=2 to msk do
			begin
			n:=0;
			if x=0 then
				begin
				if msk mod i=0 then
					begin
					while (test mod i=0) do
						begin
						test:=test div i;
						x:=1;
						n:=n+1;
						end;
					if n=1 then
						begin
						write(i);
						end;
					if n>1 then
						begin
						write(i,'^', n);
						end;
					end;
				end
			else
				begin
				if msk mod i=0 then
					begin
					while (test mod i=0) do
						begin
						test:=test div i;
						x:=1;
						n:=n+1;
						end;
					if n=1 then
						begin
						write(' x ',i);
						end;
					if n>1 then
						begin
						write(' x ',i,'^', n);
						end;
					end;
				end;
			end;
		end;
	writeln;
end.