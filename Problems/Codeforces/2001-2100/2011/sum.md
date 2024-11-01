A.
```kotlin
import kotlin.math.max

fun solve() {
    val n = readln().toInt()

    val arr = readln().split(" ").map { it.toInt() }

    var mx = 0
    for (i in 0..<n - 1) {
        mx = max(mx, arr[i])
    }

    if (mx == arr[n - 1] - 1) {
        println(mx)
    } else {
        println("Ambiguous")
    }
}

fun main() {
    var cnt = readln().toInt()
    while (cnt > 0) {
        solve()
        cnt--
    }
}
```

B.
```kotlin
fun main() {
    repeat(readln().toInt()) {
        val n = readln().toInt()
        print(1)
        print(" ")
        for (i in n downTo 2) {
            print(i)
            print(" ")
        }
        println()
    }
}
```