or(auto i : {-1,1}) {
            int nd = (d + i + 4) % 4;
            if (cnt[x][y][dir[nd]]) continue;
            cnt[x][y][dir[nd]] = cnt[x][y][dir[d]] + 1;
            q.push({x,y,nd});
        }