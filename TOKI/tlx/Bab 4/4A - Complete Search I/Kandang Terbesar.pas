var
	mx,my,ix,iy,bx,by,kx,ky,n,b,k,eq:longint;
	tnd:array[0..1000,0..1000] of longint;
	tesx,tesy:array[0..4] of longint;
	vis:array[0..1000,0..1000] of boolean;
	brs:ansistring;
procedure dfs(y,x:longint);
var i,tempx,tempy:longint;
    begin
    //tnd[y,x]:=1;
	vis[y,x]:=true;
    n:=n+1;
	for i:=1 to 4 do
	begin
		tempy:=y+tesy[i];
		tempx:=x+tesx[i];
		if((tempy>0) and (tempy<=my) and (tempx>0) and (tempx<=mx)) then
		begin
			if((vis[tempy,tempx]=false) and ((tnd[tempy,tempx]=0) or (tnd[tempy,tempx]=2) or (tnd[tempy,tempx]=3))) then
			begin
				dfs(tempy,tempx);
			end;
		end;
	end;
	
    end;
begin
	tesx[1]:=0;
	tesx[2]:=-1;
	tesx[3]:=0;
	tesx[4]:=1;
	
	tesy[1]:=1;
	tesy[2]:=0;
	tesy[3]:=-1;
	tesy[4]:=0;
	readln(mx,my);
	for iy:=1 to my do
		begin
		for ix:=1 to mx do
			begin
			tnd[iy,ix]:=0;
			vis[iy,ix]:=false;
			end;
		end;
	for iy:=1 to my do
		begin
		readln(brs);
		for ix:=1 to mx do
			begin
			if brs[ix]='#' then
				begin
				tnd[iy,ix]:=1;
				end;
			if brs[ix]='B' then
				begin
				bx:=ix;
				by:=iy;
				tnd[iy,ix]:=2;
				end;
			if brs[ix]='K' then
				begin
				kx:=ix;
				ky:=iy;
				tnd[iy,ix]:=3;
				end;
			end;
		end;
	eq:=0;
	n:=0;
	dfs(by,bx);
	b:=n;
	n:=0;
	for iy:=1 to my do
	for ix:=1 to mx do
	vis[iy,ix]:=false;
	dfs(ky,kx);
	k:=n;
	
	//writeln(b,' ',k,'zzzzzzzzzzzzzzzzzz');
		//begin
		if b>k then
			begin
			writeln('B ', b-k);
			end;
		if k>b then
			begin
			writeln('K ', k-b);
			end;
		if b=k then
			begin
			writeln('SERI');
			end;
		//end;
end.