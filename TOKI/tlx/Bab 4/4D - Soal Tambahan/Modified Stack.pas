var
	list,ctr:array[0..1000] of longint;
	msk,i,ptr,nx,ny,dummy,n:longint;
	cmd:string;
	a,b,c:char;
begin
	readln(msk);
	ptr:=1;
	n:=0;
	for dummy:=1 to msk do
		begin
		read(a,b,c);
		cmd:=a+b+c;
		if cmd='add' then
			begin
			readln(nx,ny);
			list[ptr]:=nx;
			ctr[ptr]:=ny;
			ptr:=ptr+1;
			n:=n+ny;
			writeln(n);
			end;
		if cmd='del' then
			begin
			ptr:=ptr-1;
			writeln(list[ptr]);
			readln(ny);
			n:=n-ny;
			while ny>0 do
				begin
				if ny>=ctr[ptr] then
					begin
					ny:=ny-ctr[ptr];
					ptr:=ptr-1;
					end
				else
					begin
					ctr[ptr]:=ctr[ptr]-ny;
					ny:=0;
					end;
				end;
			ptr:=ptr+1;
			end;
		if cmd='adx' then
			begin
			readln(nx);
			for i:=1 to ptr-1 do
				begin
				list[i]:=list[i]+nx;
				end;
			end;
		if cmd='dex' then
			begin
			readln(nx);
			for i:=1 to ptr-1 do
				begin
				list[i]:=list[i]-nx;
				end;
			end;
		end;
end.