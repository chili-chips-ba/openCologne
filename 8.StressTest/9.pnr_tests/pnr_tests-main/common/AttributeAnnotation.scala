package firrtl

//this is a hack to make verilog wire/reg attributes like (* use_dsp = "no" *), was broken in last version of Chisel

sealed trait DescriptionAnnotation extends firrtl.annotations.Annotation {
  def target:      firrtl.annotations.Target
  def description: String
}

case class AttributeAnnotation(target: firrtl.annotations.Target, description: String) extends DescriptionAnnotation {
  def update(renames: firrtl.RenameMap): Seq[AttributeAnnotation] = {
    renames.get(target) match {
      case None      => Seq(this)
      case Some(seq) => seq.map(n => this.copy(target = n))
    }
  }
  /*override private[firrtl.annotations]*/ def dedup: Option[(Any, firrtl.annotations.Annotation, firrtl.annotations.ReferenceTarget)] = this match {
    case a @ AttributeAnnotation(refTarget: firrtl.annotations.ReferenceTarget, _) =>
      Some(((refTarget.pathlessTarget, description), copy(target = refTarget.pathlessTarget), refTarget))
    case a @ AttributeAnnotation(pathTarget: firrtl.annotations.InstanceTarget, _) =>
      Some(((pathTarget.pathlessTarget, description), copy(target = pathTarget.pathlessTarget), pathTarget.asReference))
    case _ => None
  }
}
