int solution (int X, int Y, int D)
{
    // Y - X = n * D; if n is natural number - exactly n jumps (frog ends at Y); else need n + 1 jumps (ends behind Y)
    return (Y - X) % D == 0 ? (Y - X) / D : (Y - X) / D + 1;
}
