var
	list:array[0..100,0..100] of longint;
	mskx,msky,x,y,n:longint;
	a:string;
	Z:text;
begin
	assign(Z,'crosswords.in');
	reset(Z);
	readln(Z,msky,mskx);
	for y:=0 to msky+1 do
		begin
		for x:=0 to mskx+1 do
			begin
			list[y,x]:=1;
			end;
		end;
	for y:=1 to msky do
		begin
		readln(Z,a);
		for x:=1 to mskx do
			begin
			if copy(a,x,1)='.' then
				begin
				list[y,x]:=0;
				end;
			end;
		end;
	close(Z);
	for y:=1 to msky do
		begin
		for x:=1 to mskx do
			begin
			if list[y,x]=0 then
				begin
				if list[y-1,x]=1 then
					begin
					if list[y+1,x]=0 then
						begin
							if list[y+2,x]=0 then
							begin
								begin
								list[y,x]:=3;
								end;
							end;
						end;
					end;
				end;
			if list[y,x]=0 then
				begin
				if list[y,x-1]=1 then
					begin
					if list[y,x+1]=0 then
						begin
							if list[y,x+2]=0 then
							begin
								begin
								list[y,x]:=3;
								end;
							end;
						end;
					end;
				end;
			end;
		end;
	n:=0;
	for y:=1 to msky do
		begin
		for x:=1 to mskx do
			begin
			if list[y,x]=3 then
				begin
				n:=n+1;
				end;
			end;
		end;
	assign(Z,'crosswords.out');
	rewrite(Z);
	writeln(Z,n);
	for y:=1 to msky do
		begin
		for x:=1 to mskx do
			begin
			if list[y,x]=3 then
				begin
				writeln(Z,y,' ',x);
				end;
			end;
		end;
	close(Z);
end.