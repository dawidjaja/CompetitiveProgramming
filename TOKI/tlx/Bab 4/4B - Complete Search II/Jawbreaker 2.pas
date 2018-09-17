var
	mx,my,ix,iy,bola,y,x,n,hsl,nakh:longint;
	tnd:array[0..100,0..100] of longint;
procedure dfs(yt,xt,bola:longint);
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
			dfs(yt,xt,bola);
			end;
		xt:=xt-bx[i];
		yt:=yt-by[i];
		end;
end;
begin
readln(my,mx);
for iy:=0 to my-1 do
	begin
	for ix:=0 to mx-1 do
		begin
		read(tnd[iy,ix]);
		end;
	end;
nakh:=1;
for y:=0 to my-1 do
	begin
	for x:=0 to mx-1 do
		begin
		if tnd[y,x]<>0 then
			begin
			bola:=tnd[y,x];
			n:=0;
			dfs(y,x,bola);
			if n>nakh then
			nakh:=n;
			end;
		end;
	end;
hsl:=nakh*(nakh-1);
writeln(hsl);
end.