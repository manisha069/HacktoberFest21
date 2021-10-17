import Foundation

public class DynamicCollectionView: UICollectionView {

    override public func layoutSubviews() {
        super.layoutSubviews()
        if !bounds.size.equalTo(intrinsicContentSize) {
            invalidateIntrinsicContentSize()
        }
    }

    override public var intrinsicContentSize: CGSize {
        let intrinsicContentSize: CGSize = contentSize
        return intrinsicContentSize
    }
}
