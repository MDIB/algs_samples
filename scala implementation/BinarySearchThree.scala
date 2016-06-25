

/**
  * Created by michel on 25/06/16.
  */

  abstract class IntSet {
    def contains(x: Int): Boolean
    def incl(x: Int): IntSet
    def union(other: IntSet) : IntSet
  }

  class NonEmpty(elem: Int, left: IntSet, right: IntSet) extends IntSet {
    def contains(x: Int): Boolean = {
      if (x > elem) right contains x
      else if (x < elem) left contains x
      else true
    }

    def incl(x: Int): IntSet = {
      if (x > elem) new NonEmpty(elem, left, right incl x)
      else if (x < elem) new NonEmpty(elem, left incl x, right)
      else this
    }

    def union(other: IntSet) : IntSet =
      ((left union right) union other) incl elem

    override def toString = "[" + left + elem + right + "]"
  }

  object Empty extends IntSet {
    def contains(x: Int) = false

    def incl(x: Int) = new NonEmpty(x, Empty, Empty)

    def union(other : IntSet) = other

    override def toString = "."
  }
