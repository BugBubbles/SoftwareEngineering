#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*�ܽṹΪ��struct node ����union������ǰ����ָ�룬union�е�structΪ��Ҫ���ĵ�����*/
struct mystruct1
{
  char a[5];
};
struct mystruct2
{
  char b[100];
};

union myunion
{
  struct mystruct1 name1;
  struct mystruct2 name2;
  int size; //ÿ�θ���union�ڵ�Ԫ�أ���Ӧ����size��С
};
struct node
{
  union myunion val; //ָ��union
  struct node *next, *pre;
};

int find_union(struct node *p, int find_size)
{ //���ز��ҵ�Ԫ���������е�λ�ã�dummyhead��Ϊ��0��
  p = p->next;
  int ans = 1;
  while (p->next != NULL)
  {
    if (p->val.size == find_size)
    {
      return ans;
    }
  }
  return -1; //������
}
void delete_union(struct node *p, int pos)
{
  //ɾ����pos��node,��СֵΪ1
  p->val.size = p->val.size - 1;
  for (int i = 0; i < pos; i++)
  {
    p = p->next;
  }
  struct node *tmp;
  tmp = p;
  tmp->pre->next = tmp->next;
  tmp->next->pre = tmp->pre;
  free(tmp);
  tmp = NULL;
}
void add_union(struct node *head, struct node *tail)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  //�˴�����дҪ��new_node���ӵ����ݣ�������add_union�������������Ҳ������main���������new_node������
  new_node->pre = tail->pre;
  tail->pre->next = new_node;
  new_node->next = tail;
  tail->pre = new_node;
  //����ӵ�node��dummy_tail->pre��ָ��
  head->val.size = head->val.size + 1;
}
int get_length(struct node *head)
{
  return head->val.size;
}
int main()
{
  //��ʼ��
  struct node dummy_head, dummy_tail;
  dummy_head.pre = NULL;
  dummy_head.next = &dummy_tail;
  dummy_tail.pre = &dummy_head;
  dummy_tail.next = NULL;
  dummy_head.val.size = 0; //���size������Ŵ��������Ч���ȣ�������dummy_head��dummy_tail

  //ʹ��ʵ��
  add_union(&dummy_head, &dummy_tail);
  add_union(&dummy_head, &dummy_tail);
  dummy_head.next->val.size = 50;
  dummy_head.next->next->val.size = 60;
  printf("%d\n", get_length(&dummy_head));
  delete_union(&dummy_head, 2);
  printf("%d\n", get_length(&dummy_head));
  printf("%d\n", dummy_head.next->val.size);
  printf("����Ԫ���ڵ�%d��λ��\n", find_union(&dummy_head, 50));
  /*dummy_tail.pre->val->size = 10;
  printf("%d",dummy_head.next->val->size);*/
  return 0;
}