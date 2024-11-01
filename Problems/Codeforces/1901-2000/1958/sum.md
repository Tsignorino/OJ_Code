A.
```kotlin
import kotlin.math.min

object IO {
    fun readInt() = readln().toInt()
    fun readLong() = readln().toLong()
    fun readDouble() = readln().toDouble()

    fun readStrings() = readln().split(" ")
    fun readInts() = readStrings().map { it.toInt() }
    fun readLongs() = readStrings().map { it.toLong() }
    fun readDoubles() = readStrings().map { it.toDouble() }
}

fun main() {
    repeat(IO.readInt()) {
        solve()
    }
}

fun solve() {
    val n = IO.readInt()

    var ans = 100
    for (i in 0..33) {
        for (j in 0..20) {
            val res = i * 3 + j * 5
            if (res > n) {
                continue
            }
            ans = min(ans, n - res)
        }
    }
    println(ans)
}
```

B.
```kotlin
import java.util.*
import kotlin.math.max
 
fun main() {
    val scan = Scanner(System.`in`)
    val n = scan.nextInt()
 
    for (i in 1..n) {
        val k = scan.nextInt()
        var m = scan.nextInt()
 
        m %= 3 * k
        println(max(2 * k - m, 0))
    }
}
```

C.
```kotlin
object IO {
    fun readInt() = readln().toInt()
    fun readLong() = readln().toLong()
    fun readDouble() = readln().toDouble()

    fun readStrings() = readln().split(" ")
    fun readInts() = readStrings().map { it.toInt() }
    fun readLongs() = readStrings().map { it.toLong() }
    fun readDoubles() = readStrings().map { it.toDouble() }
}


fun main() {
    repeat(IO.readInt()) {
        var (n, k) = IO.readLongs()
        while (k % 2 == 0L) {
            k /= 2
            n--
        }
        println(n)
    }
}
```

D.
```kotlin
fun readInt() = readln().toInt()
fun readLong() = readln().toLong()
fun readDouble() = readln().toDouble()
fun readStrings() = readln().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
fun readDoubles() = readStrings().map { it.toDouble() }


fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readInts()

        val dp = mutableListOf<Pair<Int, Long>>()
        dp.add(Pair(0, 0L))
        for (i in 1..n) {
            if (a[i - 1] == 0) {
                dp.add(dp[i - 1])
            } else {
                dp.add(Pair(dp[i - 1].first + 1, dp[i - 1].second + a[i - 1]))
                if (i >= 2 && a[i - 1] > 0) {
                    val other = Pair(dp[i - 2].first + 1, dp[i - 2].second + 2 * (a[i - 1] + a[i - 2]))
                    if (other.first < dp[i].first || (other.first == dp[i].first && other.second < dp[i].second)) {
                        dp[i] = other
                    }
                }
            }
        }
        println(dp[n].second)
    }
}
```