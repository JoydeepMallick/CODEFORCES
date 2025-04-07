
fun test() {
    val parts = readLine()?.split(" ")

    val a = parts?.getOrNull(0)?.toIntOrNull() ?: 0
    val b = parts?.getOrNull(1)?.toIntOrNull() ?: 0
    val c = parts?.getOrNull(2)?.toIntOrNull() ?: 0

    var n = 1

    for (i in 0 until a) {
        print(n)
        if (n == 1) {
            n = 2
        } else {
            n = 1
        }
    }
    var ch = 'A'
        for (i in 0 until b) {
        print(ch)
        if (ch == 'A') {
            ch = 'B'
        } else {
            ch = 'A'
        }
    }
    
    ch = 'a'
        for (i in 0 until c) {
        print(ch)
        if (ch == 'a') {
            ch = 'b'
        } else {
            ch = 'a'
        }
    }
    println()
}


fun main() {
    val t = readLine()?.toIntOrNull() ?: 0 

    for (i in 1..t) { 
        test() 
    }
}