var
	mx,my,ix,iy,bola,y,n,nakh,ty,tx,temp:longint;
	tnd,map:array[0..100,0..100] of longint;
procedure dfs1(yt,xt,bola:longint);
var
	i:longint;
	bx:array[1..4] of longint;
	by:array[1..4] of longint;
begin
	tnd[yt,xt]:=0;
	n:=n+1;
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
		if ((((((yt>=0)) and (xt>=0)) and (yt<=my-1)) and (xt<=mx-1)) and (tnd[yt,xt]=bola)) then
			begin
			dfs1(yt,xt,bola);
			end;
		xt:=xt-bx[i];
		yt:=yt-by[i];
		end;
end;
procedure dfs2(yt,xt,bola:longint);
var
	i:longint;
	bx:array[1..4] of longint;
	by:array[1..4] of longint;
begin
	map[yt,xt]:=0;
	n:=n+1;
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
		if ((((((yt>=0)) and (xt>=0)) and (yt<=my-1)) and (xt<=mx-1)) and (map[yt,xt]=bola)) then
			begin
			dfs2(yt,xt,bola);
			end;
		xt:=xt-bx[i];
		yt:=yt-by[i];
		end;
end;
begin
//reading
readln(my,mx);
for iy:=0 to my-1 do
	begin
	for ix:=0 to mx-1 do
		begin
		read(tnd[iy,ix]);
		map[iy,ix]:=tnd[iy,ix];
		end;
	end;
//cari yg terbesar
nakh:=1;
for iy:=0 to my-1 do
	begin
	for ix:=0 to mx-1 do
		begin
		if tnd[iy,ix]<>0 then
			begin
			bola:=tnd[iy,ix];
			n:=0;
			dfs1(iy,ix,bola);
			if n>=nakh then
				begin
				nakh:=n;
				ty:=iy;
				tx:=ix;
				end;
			end;
		end;
	end;
//penandaan yg pecah
dfs2(ty,tx,map[tx,ty]);
//penurunan yg pecah
for ix:=0 to mx-1 do
	begin
	for iy:=my-1 downto 0 do
		begin
		if map[iy,ix]=0 then
			begin
			for y:=iy downto 0 do
				begin
				if map[y,ix]<>0 then
					begin
					temp:=map[y,ix];
					map[y,ix]:=map[iy,ix];
					map[iy,ix]:=temp;
					break;
					end;
				end;
			end;
		end;
	end;
//writing
for iy:=0 to my-1 do
	begin
	for ix:=0 to mx-1 do
		begin
		if ix=0 then
			begin
			if map[iy,ix]=0 then
				begin
				write('.');
				end
			else
				begin
				write(map[iy,ix]);
				end;
			end
		else
			begin
			if map[iy,ix]=0 then
				begin
				write(' .');
				end
			else
				begin
				write(' ',map[iy,ix]);
				end;
			end;
		end;
		writeln;
	end;
end.