var
	msk,i,x,y,ny,nx,z:longint;
	tnd:array[0..100,0..100] of longint;
	brs:string;
procedure dfs(yt,xt:longint);
var
	i:longint;
	bx:array[1..4] of longint;
	by:array[1..4] of longint;
begin
	tnd[yt,xt]:=1;
	bx[1]:=0;
	by[1]:=1;
	bx[2]:=1;
	by[2]:=0;
	bx[3]:=0;
	by[3]:=-1;
	bx[4]:=-1;
	by[4]:=0;
	for i:=1 to 4 do
		begin
		xt:=xt+bx[i];
		yt:=yt+by[i];
		if (((((yt>=0)) and (xt>=0)) and (yt<=y+1)) and (xt<=x+1) and (tnd[yt,xt]=0)) then
			begin
			dfs(yt,xt);
			end;
		xt:=xt-bx[i];
		yt:=yt-by[i];
		end;
end;
begin
	readln(msk);
	for i:=1 to msk do
	begin
		readln(y,x);
		for ny:=0 to y+1 do
			begin
			for nx:=0 to x+1 do
				begin
				tnd[ny,nx]:=0;
				end;
			end;
		for ny:=1 to y do
			begin
			readln(brs);
			for nx:=1 to x do 
				begin
				if copy(brs,nx,1)='#' then
					begin
					tnd[ny,nx]:=1;
					end;
				end;
			end;
		dfs(0,0);
		z:=0;
		for ny:=0 to y+1 do
			begin
			for nx:=0 to x+1 do
				begin
				if tnd[ny,nx]=0 then
					begin
					z:=1;
					end;
				end;
			end;
		if z=0 then
			begin
			writeln('TIDAK');
			end;
		if z=1 then
			begin
			writeln('YA');
			end;
	end;
end.